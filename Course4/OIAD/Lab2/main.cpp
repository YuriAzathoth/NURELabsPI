#define DOTS_COUNT 350
#define CLUSTERS_COUNT 3
#define CLUSTER_ERROR 0.6

#include "Clusterise.h"
#include "PolygonUtil.h"
#include "Renderer.h"
#include "SimilarityMatrix.h"
#include <glm/vec2.hpp>
#include <random>
#include <vector>

#include <iostream>

int main()
{
	std::random_device randDev;
	std::mt19937 mt(randDev());
	std::uniform_real_distribution<float> random(-0.9f, 0.9f);

	std::vector<glm::vec2> vertices(DOTS_COUNT);
	for(glm::vec2& vertex : vertices)
	{
		vertex.x = random(mt);
		vertex.y = random(mt);
	}

	try
	{
		const glm::vec3 DOT_COLORS[] = {{1.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}};
		const glm::vec3 AREA_COLORS[] = {{1.0f, 0.9f, 0.9f}, {0.9f, 1.0f, 0.9f}, {0.9f, 0.9f, 1.0f}};
		std::vector<glm::vec2> temp;

		Clusters clusters = Clusterise(vertices, CLUSTERS_COUNT);
		Renderer renderer;
		for(unsigned i = 0; i < CLUSTERS_COUNT; ++i)
		{
			renderer.AddDots(clusters.clusters_[i].area_, DOT_COLORS[i], 0.8f, 4.0f);
			renderer.AddShape(GenerateConvex(clusters.clusters_[i].area_), AREA_COLORS[i], 0.9f);

			temp.clear();
			temp.push_back(clusters.clusters_[i].center_);
			renderer.AddDots(temp, DOT_COLORS[i], 0.7f, 8.0f);
		}
		renderer.Run();
	}
	catch(std::exception& e)
	{
		std::cerr << "And exception has iccured: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
