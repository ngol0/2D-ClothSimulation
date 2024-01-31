#include "point.h"
#include "renderer.h"

point::point(vec2 pos, float m) : pos(pos), prev_pos(pos), mass(m)
{
	acceleration.x = force.x / mass;
	acceleration.y = force.y / mass;
}

void point::update(float deltaTime, int win_width, int win_height)
{
	vec2 temp_pos = pos;

	pos.x = 2 * pos.x - prev_pos.x + acceleration.x * (deltaTime * deltaTime);
	pos.y = 2 * pos.y - prev_pos.y + acceleration.y * (deltaTime * deltaTime);

	prev_pos = temp_pos;

	keep_inside_view(win_width, win_height);
}

void point::keep_inside_view(int win_width, int win_height)
{
	if (pos.x > win_width)
	{
		pos.x = win_width;
		prev_pos.x = pos.x;
	}
	else if (pos.x < 0)
	{
		pos.x = 0;
		prev_pos.x = pos.x;
	}

	if (pos.y > win_height)
	{
		pos.y = win_height;
		prev_pos.y = pos.y;
	}
	else if (pos.y < 0)
	{
		pos.y = 0;
		prev_pos.y = pos.y;
	}
}

void point::draw(renderer& draw)
{
	draw.drawn_point(pos.x, pos.y, 0xFF0048E3);
}