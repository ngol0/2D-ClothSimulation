#pragma once
#include "point.h"
#include "vec2.h"
#include <math.h>

namespace utils
{
	float distance_point(const point& p1, const point& p2);
	float vector_length(const vec2& v);
}