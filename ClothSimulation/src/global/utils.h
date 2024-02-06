#pragma once
#include "rect/particle.h"
#include "vec2.h"
#include <math.h>

namespace utils
{
	float distance_point(const particle& p1, const particle& p2);
	float vector_length(const vec2& v);
}