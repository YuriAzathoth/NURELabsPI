#pragma once

#include <glm/vec2.hpp>
#include <vector>

struct Cluster
{
	std::vector<glm::vec2> area_;
	glm::vec2 center_;
};

struct Clusters
{
	std::vector<Cluster> clusters_;
};

Clusters Clusterise(const std::vector<glm::vec2>& vertices, unsigned count);
