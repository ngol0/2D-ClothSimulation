#pragma once
#include "global/vec2.h"

class renderer;
class cloth_stick;
struct mouse;

struct point
{
private:
	cloth_stick* sticks[2]{ nullptr };

	bool b_selected{ false };
	bool b_pinned{ false };

	vec2 pos;
	vec2 prev_pos;
	vec2 initial_pos;

public:
	point() : pos(vec2()){};
	point(vec2 pos);
	
	void keep_inside_view(int win_width, int win_height);
	void update(float deltaTime, mouse& mouse, const vec2& acceleration, float drag, float elasticity, int win_width, int win_height);
	void draw(renderer& renderer);

	void add_stick(cloth_stick& stick, int side);
	void pin();

	const vec2& get_pos() { return pos; }
	void set_pos(const vec2& position) { this->pos = position; }
};