#include "Clusterise.h"
#include <GLM/geometric.hpp>
#include <algorithm>
#include <random>
#include <set>
#include <unordered_map>

#include <iostream>

Clusters Clusterise(const std::vector<glm::vec2>& vertices, unsigned count)
{
	Clusters ret;
	ret.clusters_.resize(count);

	std::random_device randDev;
	std::mt19937 mt(randDev());
	std::uniform_int_distribution<unsigned> random(0, static_cast<unsigned>(vertices.size()));

	unsigned i;
	unsigned j;

	std::set<unsigned> uniqueIds;
	for(i = 0; i < count; ++i)
		do
		{
		} while(!uniqueIds.insert(random(mt)).second);

	auto uniqueIt = uniqueIds.cbegin();
	for(i = 0; i < count; ++i, ++uniqueIt)
		ret.clusters_[i].center_ = vertices[*uniqueIt];

	std::vector<unsigned> classes(vertices.size());
	std::vector<std::vector<float>> distances(vertices.size());
	for(std::vector<float>& classDistances : distances)
		classDistances.resize(count);

	auto minDistanceIt = distances.back().begin();
	unsigned newClass;
	float classesCount;

	for(i = 0; i < static_cast<unsigned>(vertices.size()); ++i)
		for(j = 0; j < count; ++j)
			distances[i][j] = glm::distance(vertices[i], ret.clusters_[j].center_);
	for(i = 0; i < static_cast<unsigned>(vertices.size()); ++i)
	{
		minDistanceIt = std::min_element(distances[i].begin(), distances[i].end());
		classes[i] = std::distance(distances[i].begin(), minDistanceIt);
	}

	do
	{
		for(i = 0; i < count; ++i)
		{
			classesCount = static_cast<float>(std::count(classes.begin(), classes.end(), i));
			ret.clusters_[i].center_.x = 0.0f;
			ret.clusters_[i].center_.y = 0.0f;
			for(j = 0; j < static_cast<unsigned>(vertices.size()); ++j)
				if(classes[j] == i)
					ret.clusters_[i].center_ += vertices[j];
			ret.clusters_[i].center_.x /= classesCount;
			ret.clusters_[i].center_.y /= classesCount;
		}

		for(i = 0; i < static_cast<unsigned>(vertices.size()); ++i)
			for(j = 0; j < count; ++j)
				distances[i][j] = glm::distance(vertices[i], ret.clusters_[j].center_);

		classesCount = 0.0f;
		for(i = 0; i < static_cast<unsigned>(vertices.size()); ++i)
		{
			minDistanceIt = std::min_element(distances[i].begin(), distances[i].end());
			newClass = std::distance(distances[i].begin(), minDistanceIt);
			if(classes[i] != newClass)
			{
				classes[i] = newClass;
				++classesCount;
			}
		}
	} while(classesCount);

	for(i = 0; i < static_cast<unsigned>(vertices.size()); ++i)
		ret.clusters_[classes[i]].area_.push_back(vertices[i]);

	return ret;
}
