#include "cloth.h"
#include "renderer.h"
#include "point.h"
#include "cloth_stick.h"

cloth::cloth() {}

void cloth::init(vec2 start_pos, vec2 size, float spacing)
{
	float number_of_horizontal_rect = size.x / spacing;
	float number_of_vertical_rect = size.y / spacing;

	//create points and stick
	for (int y = 0; y <= number_of_vertical_rect; y++)
	{
		for (int x = 0; x <= number_of_horizontal_rect; x++)
		{
			point* p = new point(vec2(start_pos.x + spacing * x, start_pos.y + spacing * y));

			//if not the first point, create the stick to the left
			if (x != 0)
			{
				point* left_p = points[points.size() - 1];
				cloth_stick* stick = new cloth_stick(*p, *left_p, spacing);

				//add sticks to points
				p->add_stick(*stick, 0);
				left_p->add_stick(*stick, 0);

				//push into vector
				sticks.push_back(stick);
			}

			//if not the first point, create the stick up
			if (y != 0)
			{
				point* up_p = points[points.size() - (number_of_horizontal_rect + 1)];
				cloth_stick* stick = new cloth_stick(*p, *up_p, spacing);

				//add sticks to points
				p->add_stick(*stick, 1);
				up_p->add_stick(*stick, 1);

				//push into vector
				sticks.push_back(stick);
			}

			if (y == 0 && x % 2 == 0) 
			{
				p->pin();
			}

			points.push_back(p);
		}
	}
}

void cloth::update(float deltaTime, renderer& renderer, mouse& mouse)
{
	for (auto& p : points)
	{
		p->update(deltaTime, mouse, gravity, drag, elasticity, renderer.get_win_width(), renderer.get_win_height());
	}

	for (auto& s : sticks)
	{
		s->update(deltaTime);
	}
}

void cloth::draw(renderer& renderer)
{
	for (auto& s : sticks)
	{
		s->draw(renderer);
	}
}

void cloth::shutdown()
{
	for (auto& p : points)
	{
		delete(p);
	}

	for (auto& s : sticks)
	{
		delete(s);
	}
}