#pragma once
#include "vec2.h"

class renderer;

struct point
{
public:
	point() : pos(vec2()), mass(0.f) {};
	point(vec2 pos, float m);

	vec2 pos;
	vec2 prev_pos;
	float mass;
	vec2 force{ 0.f, 981.0f };
	vec2 acceleration;

	void keep_inside_view(int win_width, int win_height);
	void update(float deltaTime, int win_width, int win_height);
	void draw(renderer& renderer);
};