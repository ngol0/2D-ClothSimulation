#pragma once
#include "global/vec2.h"

struct mouse
{
	bool left_mouse_down() { return is_left_mouse_down; }
	bool right_mouse_down() { return is_right_mouse_down; }
	void set_left_mouse(bool state) { is_left_mouse_down = state; }
	void set_right_mouse(bool state) { is_right_mouse_down = state; }

	const vec2& get_pos() { return cur_pos; }
	const vec2& get_prev_pos() { return prev_pos; }
	float get_cursor_size() { return cursor_size; }

	void increase_cursor(int amount);
	void update_pos(const vec2& pos);

private:
	bool is_left_mouse_down{ false };
	bool is_right_mouse_down{ false };

	vec2 cur_pos;
	vec2 prev_pos;

	float max_cursor_size{ 100.f };
	float min_cursor_size{ 20.f };

	float cursor_size{ 20.f };
};