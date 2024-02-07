#include "cloth_stick.h"
#include "point.h"
#include "renderer.h"
#include "global/utils.h"

cloth_stick::cloth_stick(point& m_p1, point& m_p2, float m_length) : m_p1(&m_p1), m_p2(&m_p2), m_length(m_length) {}

void cloth_stick::update(float deltaTime)
{
	if (!b_alive) return;

	vec2 diff = m_p1->get_pos() - m_p2->get_pos();
	float dist = utils::vector_length(diff);

	//tear if the distance between two points are greater than certain amount
	if (dist > m_distance_to_tear)
	{
		tear();
		return;
	}

	float diff_factor = (m_length - dist) / dist;
	vec2 offset = diff * diff_factor * 0.5f;

	m_p1->set_pos(m_p1->get_pos() + offset);
	m_p2->set_pos(m_p2->get_pos() - offset);
}

void cloth_stick::draw(renderer& r)
{
	if (!b_alive) return;
	r.drawn_line(m_p1->get_pos().x, m_p1->get_pos().y, m_p2->get_pos().x, m_p2->get_pos().y, b_selected ? m_selected_color : m_cloth_color);
}

void cloth_stick::tear()
{
	b_alive = false;
}