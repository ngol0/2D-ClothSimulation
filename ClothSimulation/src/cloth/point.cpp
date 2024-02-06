#include "point.h"
#include "renderer.h"
#include "cloth_stick.h"

point::point(vec2 pos) : pos(pos), prev_pos(pos), initial_pos(pos) {}

void point::update(float deltaTime, const vec2& acceleration, float drag, float elasticity, int win_width, int win_height)
{
	if (is_pinned)
	{
		pos = initial_pos;
		return;
	}

	vec2 temp_pos = pos;
	pos = pos + (pos - prev_pos) * (1.f - drag) + acceleration * (1.f - drag) * (deltaTime * deltaTime);
	prev_pos = temp_pos;

	keep_inside_view(win_width, win_height);
}

void point::keep_inside_view(int win_width, int win_height)
{
	if (pos.x >= win_width)
	{
		pos.x = win_width;
		prev_pos.x = pos.x;
	}
	else if (pos.x <= 0)
	{
		pos.x = 0;
		prev_pos.x = pos.x;
	}

	if (pos.y >= win_height - 10)
	{
		pos.y = win_height - 10;
		prev_pos.y = pos.y;
	}
	else if (pos.y <= 0)
	{
		pos.y = 0;
		prev_pos.y = pos.y;
	}
}

void point::draw(renderer& draw)
{
	draw.drawn_point(pos.x, pos.y, 0xffffff);
}

void point::add_stick(cloth_stick& stick, int index)
{
	sticks[index] = &stick;
}

void point::pin()
{
	is_pinned = true;
}