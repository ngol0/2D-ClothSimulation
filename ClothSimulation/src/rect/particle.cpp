#include "particle.h"
#include "renderer.h"

particle::particle(vec2 pos, float mass) : pos(pos), prev_pos(pos), mass(mass)
{
	acceleration.x = force.x / mass;
	acceleration.y = force.y / mass;
}

void particle::update(float deltaTime, int win_width, int win_height)
{
	vec2 temp_pos = pos;

	pos.x = 2 * pos.x - prev_pos.x + acceleration.x * (deltaTime * deltaTime);
	pos.y = 2 * pos.y - prev_pos.y + acceleration.y * (deltaTime * deltaTime);

	prev_pos = temp_pos;

	keep_inside_view(win_width, win_height);
}

void particle::keep_inside_view(int win_width, int win_height)
{
	if (pos.x >= win_width)
	{
		pos.x = win_width;
	}
	else if (pos.x <= 0)
	{
		pos.x = 0;
	}

	if (pos.y >= win_height - 10)
	{
		pos.y = win_height - 10;
	}
	else if (pos.y <= 0)
	{
		pos.y = 0;
	}
}

void particle::draw(renderer& draw)
{
	draw.drawn_point(pos.x, pos.y, 0xffffff);
}