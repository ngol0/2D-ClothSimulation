#include "mouse.h"

void mouse::increase_cursor(int amount)
{
	if (cursor_size + amount > max_cursor_size || cursor_size + amount < min_cursor_size) 
	{
		return;
	}
	cursor_size += amount;
}

void mouse::update_pos(const vec2& pos)
{
	prev_pos = cur_pos;
	cur_pos = pos;
}