#include "utils.h"

namespace utils
{
	float distance_point(const particle& p1, const particle& p2)
	{
		float dx = p1.pos.x - p2.pos.x;
		float dy = p1.pos.y - p2.pos.y;
		return sqrt(dx * dx + dy * dy);
	}

	float vector_length(const vec2& v)
	{
		return sqrt(v.x * v.x + v.y * v.y);
	}
}