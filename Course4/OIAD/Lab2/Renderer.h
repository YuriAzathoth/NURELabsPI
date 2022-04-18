#pragma once

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <vector>

struct SDL_Window;
typedef void* SDL_GL_Context;

class Renderer
{
  public:
	Renderer();
	~Renderer();

	void Run();

	void AddDots(const std::vector<glm::vec2>& vertices, const glm::vec3& color, float depth, float size);
	void AddShape(const std::vector<glm::vec2>& vertices, const glm::vec3& color, float depth);
	void Clear();

  private:
	unsigned CreateGpuProgram(const char* vertexShaderSource, const char* fragmentShaderSource);

	struct Point
	{
		glm::vec3 color;
		float depth;
		float size;
		unsigned vao;
		unsigned vbo;
		unsigned count;
	};

	struct Polygon
	{
		glm::vec3 color;
		float depth;
		unsigned vao;
		unsigned vbo;
		unsigned ebo;
		unsigned count;
	};

	SDL_Window* window_;
	SDL_GL_Context context_;
	std::vector<Point> points_;
	std::vector<Polygon> polygons_;
	unsigned dotsProgram_;
	unsigned dotsPosition_;
	unsigned dotsColor_;
	unsigned dotsDepth_;
	unsigned dotsSize_;
	unsigned polyProgram_;
	unsigned polyPosition_;
	unsigned polyColor_;
	unsigned polyDepth_;

	Renderer(const Renderer&) = delete;
	void operator=(const Renderer&) = delete;
};
