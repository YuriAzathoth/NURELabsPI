#pragma once

#include <GLM/vec2.hpp>
#include <vector>

std::vector<glm::vec2> GenerateConvex(const std::vector<glm::vec2>& concave);
void SortClockwise(std::vector<glm::vec2>& convex);
