#include "utils.h"

namespace utils
{
	float vector_length(const vec2& v)
	{
		return sqrtf(v.x * v.x + v.y * v.y);
	}

	float squared_vector_length(const vec2& v)
	{
		return v.x * v.x + v.y * v.y;
	}
}