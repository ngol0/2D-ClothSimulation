#include "point.h"
#include "renderer.h"
#include "cloth_stick.h"
#include "mouse.h"
#include "global/utils.h"

point::point(vec2 pos) : pos(pos), prev_pos(pos), initial_pos(pos) {}

void point::update(float deltaTime, mouse& mouse, const vec2& acceleration, float drag, float elasticity, int win_width, int win_height)
{
	//get mouse
	vec2 to_mouse_vector = mouse.get_pos() - pos;
	float distance_to_mouse = utils::squared_vector_length(to_mouse_vector);

	b_selected = distance_to_mouse < mouse.get_cursor_size() * mouse.get_cursor_size();

	//set stick selected state
	for (auto& s : sticks)
	{
		if (s != nullptr)
		{
			s->set_selected(b_selected);
		}
	}

	//dragging the cloth
	if (mouse.left_mouse_down() && b_selected)
	{
		vec2 mouse_diff = mouse.get_pos() - mouse.get_prev_pos();

		if (mouse_diff.x > elasticity) mouse_diff.x = elasticity;
		if (mouse_diff.y > elasticity) mouse_diff.y = elasticity;
		if (mouse_diff.x < -elasticity) mouse_diff.x = -elasticity;
		if (mouse_diff.y < -elasticity) mouse_diff.y = -elasticity;

		prev_pos = pos - mouse_diff;
	}

	//tearing the cloth
	if (mouse.right_mouse_down() && b_selected)
	{
		for (auto& s : sticks)
		{
			if (s != nullptr)
			{
				s->tear();
			}
		}
	}

	if (b_pinned)
	{
		pos = initial_pos;
		return;
	}

	//verlet integration
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
	b_pinned = true;
}