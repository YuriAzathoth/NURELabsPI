#include "PolygonUtil.h"
#include <GLM/geometric.hpp>
#include <GLM/gtx/hash.hpp>
#include <GLM/trigonometric.hpp>
#include <cmath>
#include <unordered_set>

static inline int FindSide(const glm::vec2& begin, const glm::vec2& end, const glm::vec2& point);
static inline float LineDist(const glm::vec2& begin, const glm::vec2& end, const glm::vec2& point) noexcept;
static inline void QuickHull(std::unordered_set<glm::vec2>& convexVertices,
                             const std::vector<glm::vec2>& concave,
                             const glm::vec2& begin,
                             const glm::vec2& end,
                             int side);

std::vector<glm::vec2> GenerateConvex(const std::vector<glm::vec2>& concave)
{
	const auto [minXIt, maxXIt] = std::minmax_element(
	    concave.cbegin(), concave.cend(), [](const glm::vec2& lhs, const glm::vec2& rhs) { return lhs.x < rhs.x; });
	const int minX = std::distance(concave.begin(), minXIt);
	const int maxX = std::distance(concave.begin(), maxXIt);

	std::unordered_set<glm::vec2> convexVertices;
	QuickHull(convexVertices, concave, concave[minX], concave[maxX], 1);
	QuickHull(convexVertices, concave, concave[minX], concave[maxX], -1);

	std::vector<glm::vec2> ret(convexVertices.begin(), convexVertices.end());
	SortClockwise(ret);
	return ret;
}

void SortClockwise(std::vector<glm::vec2>& convex)
{
	glm::vec2 center(0.0f);
	for(const glm::vec2& vertice : convex)
		center += vertice;
	center.x /= convex.size();
	center.y /= convex.size();
	std::sort(convex.begin(), convex.end(),
	          [&center](const glm::vec2& lhs, const glm::vec2& rhs) -> bool
	          {
		          const float a1 = remainder(glm::degrees(atan2(lhs.x - center.x, lhs.y - center.y)) + 360.0f, 360.0f);
		          const float a2 = remainder(glm::degrees(atan2(rhs.x - center.x, rhs.y - center.y)) + 360.0f, 360.0f);
		          return a1 - a2 < 0;
	          });
}

inline int FindSide(const glm::vec2& begin, const glm::vec2& end, const glm::vec2& point)
{
	float ret = (point.y - begin.y) * (end.x - begin.x) - (end.y - begin.y) * (point.x - begin.x);
	if(ret > 0)
		return 1;
	else if(ret < 0)
		return -1;
	else
		return 0;
}

static inline float LineDist(const glm::vec2& begin, const glm::vec2& end, const glm::vec2& point) noexcept
{
	return abs((point.y - begin.y) * (end.x - begin.x) - (end.y - begin.y) * (point.x - begin.x));
}

static inline void QuickHull(std::unordered_set<glm::vec2>& convexVertices,
                             const std::vector<glm::vec2>& concave,
                             const glm::vec2& begin,
                             const glm::vec2& end,
                             int side)
{
	int ind = -1;
	float maxDist = 0.0f;
	float temp;

	for(int i = 0; i < static_cast<unsigned>(concave.size()); ++i)
	{
		const glm::vec2& next = concave[i];
		temp = LineDist(begin, end, next);
		if(FindSide(begin, end, next) == side && temp > maxDist)
		{
			ind = i;
			maxDist = temp;
		}
	}

	if(ind == -1)
	{
		convexVertices.insert(begin);
		convexVertices.insert(end);
	}
	else
	{
		const glm::vec2& next = concave[ind];
		QuickHull(convexVertices, concave, next, begin, -FindSide(next, begin, end));
		QuickHull(convexVertices, concave, next, end, -FindSide(next, end, begin));
	}
}
