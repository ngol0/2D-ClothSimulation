#include "cloth_stick.h"
#include "point.h"
#include "renderer.h"
#include "global/utils.h"

cloth_stick::cloth_stick(point& p1, point& p2, float length) : p1(&p1), p2(&p2), length(length) {}

void cloth_stick::update(float deltaTime)
{
	if (!b_alive) return;

	vec2 diff = p1->get_pos() - p2->get_pos();
	float dist = utils::vector_length(diff);
	float diff_factor = (length - dist) / dist;
	vec2 offset = diff * diff_factor * 0.5f;

	p1->set_pos(p1->get_pos() + offset);
	p2->set_pos(p2->get_pos() - offset);
}

void cloth_stick::draw(renderer& r)
{
	if (!b_alive) return;
	r.drawn_line(p1->get_pos().x, p1->get_pos().y, p2->get_pos().x, p2->get_pos().y, b_selected ? m_selected_color : m_cloth_color);
}

void cloth_stick::tear()
{
	b_alive = false;
}