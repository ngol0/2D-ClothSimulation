#pragma once
#include "global/vec2.h"

class renderer;

struct particle
{
public:
	particle() : particle(vec2(), 0.f) {};
	particle(vec2 pos, float mass);

	vec2 pos;
	vec2 prev_pos;
	//bool is_pinned{ false };
	float mass;
	vec2 force{ 0.f, 981.0f };
	vec2 acceleration;

	void keep_inside_view(int win_width, int win_height);
	void update(float deltaTime, int win_width, int win_height);
	void draw(renderer& renderer);
}; 
