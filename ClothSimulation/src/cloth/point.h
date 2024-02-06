#pragma once
#include "global/vec2.h"

class renderer;
class cloth_stick;

struct point
{
private:
	cloth_stick* sticks[2]{ nullptr };

public:
	point() : pos(vec2()){};
	point(vec2 pos);

	vec2 pos;
	vec2 prev_pos;
	vec2 initial_pos;
	bool is_pinned{ false };

	void keep_inside_view(int win_width, int win_height);
	void update(float deltaTime, const vec2& acceleration, float drag, float elasticity, int win_width, int win_height);
	void draw(renderer& renderer);

	void add_stick(cloth_stick& stick, int side);
	void pin();
};