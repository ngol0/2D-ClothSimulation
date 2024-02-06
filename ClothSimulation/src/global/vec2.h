#pragma once

struct vec2
{
	float x;
	float y;

	vec2() : x(0), y(0) { }
	vec2(float x, float y) : x(x), y(y) {}
	~vec2() = default;

	vec2 operator + (const vec2& v) const
	{
		vec2 result;
		result.x = x + v.x;
		result.y = y + v.y;
		return result;
	}

	vec2 operator - (const vec2& v) const
	{
		vec2 result;
		result.x = x - v.x;
		result.y = y - v.y;
		return result;
	}

	vec2 operator * (const float n) const
	{
		vec2 result;
		result.x = x * n;
		result.y = y * n;
		return result;
	}

	vec2 operator / (const float n) const
	{
		vec2 result;
		result.x = x / n;
		result.y = y / n;
		return result;
	}
};