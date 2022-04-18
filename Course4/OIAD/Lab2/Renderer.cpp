#include "Renderer.h"
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <glm/gtc/type_ptr.hpp>
#include <stdexcept>
#include <string>

#define WINDOW_TITLE "Lab 1"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define GL_VERSION_MAJOR 3
#define GL_VERSION_MINOR 0

static const char* DOTS_VERTEX_SHADER = "#version 330 core\n"
                                        "\n"
                                        "layout (location = 0) in vec2 aPos;\n"
                                        "\n"
                                        "uniform float cDepth;\n"
                                        "uniform float cSize;\n"
                                        "\n"
                                        "void main()\n"
                                        "{\n"
                                        "    gl_PointSize = cSize;\n"
                                        "    gl_Position = vec4(aPos, cDepth, 1.0);\n"
                                        "}\n";

static const char* DOTS_FRAGMENT_SHADER = "#version 330 core\n"
                                          "\n"
                                          "out vec4 FragColor;\n"
                                          "\n"
                                          "uniform vec3 cColor;\n"
                                          "\n"
                                          "void main()\n"
                                          "{\n"
                                          "    FragColor = vec4(cColor, 1.0);\n"
                                          "}\n";

static const char* POLY_VERTEX_SHADER = "#version 330 core\n"
                                        "\n"
                                        "layout (location = 0) in vec2 aPos;\n"
                                        "\n"
                                        "uniform float cDepth;\n"
                                        "\n"
                                        "void main()\n"
                                        "{\n"
                                        "    gl_Position = vec4(aPos, cDepth, 1.0);\n"
                                        "}\n";

static const char* POLY_FRAGMENT_SHADER = "#version 330 core\n"
                                          "\n"
                                          "out vec4 FragColor;\n"
                                          "\n"
                                          "uniform vec3 cColor;\n"
                                          "\n"
                                          "void main()\n"
                                          "{\n"
                                          "    FragColor = vec4(cColor, 1.0);\n"
                                          "}\n";

Renderer::Renderer()
    : window_(nullptr)
    , context_(nullptr)
    , dotsProgram_(0)
    , dotsPosition_(0)
    , dotsColor_(0)
    , dotsDepth_(0)
    , dotsSize_(0)
    , polyProgram_(0)
    , polyPosition_(0)
    , polyColor_(0)
    , polyDepth_(0)
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
		throw std::runtime_error(std::string("Failed to init SDL: ") + SDL_GetError());

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, GL_VERSION_MAJOR);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, GL_VERSION_MINOR);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	window_ = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH,
	                           WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if(!window_)
		throw std::runtime_error(std::string("Failed to create SDL window: ") + SDL_GetError());

	context_ = SDL_GL_CreateContext(window_);
	if(!context_)
		throw std::runtime_error(std::string("Failed to create SDL OpenGL context: ") + SDL_GetError());
	{
		glewExperimental = GL_TRUE;
		GLenum status = glewInit();
		if(status != GL_NO_ERROR)
			throw std::runtime_error(std::string("Failed to init GLEW: ") +
			                         reinterpret_cast<const char*>(glewGetErrorString(status)));
	}

	dotsProgram_ = CreateGpuProgram(DOTS_VERTEX_SHADER, DOTS_FRAGMENT_SHADER);
	dotsPosition_ = glGetAttribLocation(dotsProgram_, "aPos");
	dotsColor_ = glGetUniformLocation(dotsProgram_, "cColor");
	dotsDepth_ = glGetUniformLocation(dotsProgram_, "cDepth");
	dotsSize_ = glGetUniformLocation(dotsProgram_, "cSize");

	polyProgram_ = CreateGpuProgram(POLY_VERTEX_SHADER, POLY_FRAGMENT_SHADER);
	polyPosition_ = glGetAttribLocation(polyProgram_, "aPos");
	polyColor_ = glGetUniformLocation(polyProgram_, "cColor");
	polyDepth_ = glGetUniformLocation(polyProgram_, "cDepth");

	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	glFrontFace(GL_CCW);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

Renderer::~Renderer()
{
	Clear();
	if(polyProgram_)
		glDeleteProgram(polyProgram_);
	if(dotsProgram_)
		glDeleteProgram(dotsProgram_);
	if(context_)
		SDL_GL_DeleteContext(context_);
	if(window_)
		SDL_DestroyWindow(window_);
	SDL_Quit();
}

void Renderer::Run()
{
	SDL_Event event;
	bool run = true;
	while(run)
	{
		while(SDL_PollEvent(&event))
			if(event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
				run = false;

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(dotsProgram_);
		for(const auto& point : points_)
		{
			glUniform3fv(dotsColor_, 1, glm::value_ptr(point.color));
			glUniform1f(dotsDepth_, point.depth);
			glUniform1f(dotsSize_, point.size);
			glBindVertexArray(point.vao);
			glDrawArrays(GL_POINTS, 0, point.count);
			glBindVertexArray(0);
		}

		glUseProgram(polyProgram_);
		for(const auto& polygon : polygons_)
		{
			glUniform3fv(polyColor_, 1, glm::value_ptr(polygon.color));
			glUniform1f(polyDepth_, polygon.depth);
			glBindVertexArray(polygon.vao);
			glDrawElements(GL_TRIANGLES, polygon.count, GL_UNSIGNED_INT, nullptr);
			glBindVertexArray(0);
		}

		SDL_GL_SwapWindow(window_);
	}
}

void Renderer::AddDots(const std::vector<glm::vec2>& vertices, const glm::vec3& color, float depth, float size)
{
	points_.emplace_back();
	Point& point = points_.back();
	point.color = color;
	point.depth = depth;
	point.size = size;
	point.count = static_cast<unsigned>(vertices.size());

	glCreateVertexArrays(1, &point.vao);
	glBindVertexArray(point.vao);

	glGenBuffers(1, &point.vbo);
	glBindBuffer(GL_ARRAY_BUFFER, point.vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec2), vertices.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(dotsPosition_);
	glVertexAttribPointer(dotsPosition_, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

	glBindVertexArray(0);
}

void Renderer::AddShape(const std::vector<glm::vec2>& vertices, const glm::vec3& color, float depth)
{
	const unsigned vertexCount = static_cast<unsigned>(vertices.size());

	polygons_.emplace_back();
	Polygon& polygon = polygons_.back();
	polygon.color = color;
	polygon.depth = depth;
	polygon.count = vertexCount * 3;

	glm::vec2 box[2];
	for(const glm::vec2& vertex : vertices)
	{
		if(vertex.x < box[0].x)
			box[0].x = vertex.x;
		if(vertex.y < box[0].y)
			box[0].y = vertex.y;
		if(vertex.x > box[1].x)
			box[1].x = vertex.x;
		if(vertex.y > box[1].y)
			box[1].y = vertex.y;
	}

	glm::vec2 center = (box[0] + box[1]) / 2.0f;
	std::vector<glm::vec2> convexVertices(vertices);
	convexVertices.push_back(center);

	std::vector<unsigned> convexIndices;
	convexIndices.reserve(polygon.count);
	for(unsigned i = 0; i < vertexCount; ++i)
	{
		convexIndices.push_back(i);
		convexIndices.push_back((i < vertexCount - 1) ? (i + 1) : 0);
		convexIndices.push_back(vertexCount);
	}

	glCreateVertexArrays(1, &polygon.vao);
	glBindVertexArray(polygon.vao);

	glGenBuffers(1, &polygon.vbo);
	glBindBuffer(GL_ARRAY_BUFFER, polygon.vbo);
	glBufferData(GL_ARRAY_BUFFER, convexVertices.size() * sizeof(glm::vec2), convexVertices.data(), GL_STATIC_DRAW);

	glGenBuffers(1, &polygon.ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, polygon.ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, convexIndices.size() * sizeof(unsigned), convexIndices.data(),
	             GL_STATIC_DRAW);

	glEnableVertexAttribArray(polyPosition_);
	glVertexAttribPointer(polyPosition_, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

	glBindVertexArray(0);
}

void Renderer::Clear()
{
	for(const auto& polygon : polygons_)
	{
		glDeleteVertexArrays(1, &polygon.vao);
		glDeleteBuffers(1, &polygon.vbo);
		glDeleteBuffers(1, &polygon.ebo);
	}
	polygons_.clear();
	for(const auto& point : points_)
	{
		glDeleteVertexArrays(1, &point.vao);
		glDeleteBuffers(1, &point.vbo);
	}
	points_.clear();
}

unsigned Renderer::CreateGpuProgram(const char* vertexShaderSource, const char* fragmentShaderSource)
{
	int status;

	unsigned vertexShader = glCreateShader(GL_VERTEX_SHADER);
	if(!vertexShader)
		throw std::runtime_error("Failed to create vertex shader");
	glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
	glCompileShader(vertexShader);
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
	if(status != GL_TRUE)
	{
		glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &status);
		std::string message;
		message.resize(status);
		glGetShaderInfoLog(vertexShader, status, nullptr, message.data());
		glDeleteShader(vertexShader);
		throw std::runtime_error("Failed to compile vertex shader: " + message);
	}

	unsigned fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	if(!fragmentShader)
		throw std::runtime_error("Failed to create fragment shader");
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
	if(status != GL_TRUE)
	{
		glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &status);
		std::string message;
		message.resize(status);
		glGetShaderInfoLog(fragmentShader, status, nullptr, message.data());
		glDeleteShader(fragmentShader);
		glDeleteShader(vertexShader);
		throw std::runtime_error("Failed to compile fragment shader: " + message);
	}

	unsigned program = glCreateProgram();
	if(!program)
		throw std::runtime_error("Failed to create GPU program");
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);
	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);
	glGetProgramiv(program, GL_LINK_STATUS, &status);
	if(status != GL_TRUE)
	{
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &status);
		std::string message;
		message.resize(status);
		glGetProgramInfoLog(program, status, nullptr, message.data());
		glDeleteProgram(program);
		throw std::runtime_error("Failed to compile fragment shader: " + message);
	}

	return program;
}
