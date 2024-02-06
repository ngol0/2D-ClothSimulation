#include "rect.h"
#include "renderer.h"
#include "global/utils.h"

void rect::init(renderer& renderer)
{
	int mid_x = renderer.get_win_width() / 2;

	points[0] = particle(vec2(mid_x - 40, 300), 10);
	points[1] = particle(vec2(mid_x + 40, 300), 10);
	points[2] = particle(vec2(mid_x + 40, 360), 10);
	points[3] = particle(vec2(mid_x - 40, 360), 10);

	sticks[0] = stick(points[0], points[1], utils::distance_point(points[0], points[1]));
	sticks[1] = stick(points[1], points[2], utils::distance_point(points[1], points[2]));
	sticks[2] = stick(points[2], points[3], utils::distance_point(points[2], points[3]));
	sticks[3] = stick(points[3], points[0], utils::distance_point(points[3], points[0]));

	sticks[4] = stick(points[0], points[2], utils::distance_point(points[0], points[2]));
	sticks[5] = stick(points[1], points[3], utils::distance_point(points[1], points[3]));
}

void rect::update(float deltaTime, renderer& renderer)
{
	for (auto& p : points)
	{
		p.update(deltaTime, renderer.get_win_width(), renderer.get_win_height());
	}

	for (auto& s : sticks)
	{
		s.update(deltaTime);
	}
}

void rect::draw(renderer& renderer)
{
	for (auto& p : points)
	{
		p.draw(renderer);
	}

	for (auto& s : sticks)
	{
		s.draw(renderer);
	}
}