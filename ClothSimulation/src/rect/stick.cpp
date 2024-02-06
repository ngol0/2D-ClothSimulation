#include "stick.h"
#include "renderer.h"
#include "particle.h"
#include "global/utils.h"

stick::stick(particle& p1, particle& p2, float length) : p1(&p1), p2(&p2), length(length)
{
	
}

void stick::update(float deltaTime)
{
	vec2 diff = p1->pos - p2->pos;
	float dist = utils::vector_length(diff);
	float diff_factor = (length - dist) / dist;
	vec2 offset = diff * diff_factor * 0.5f;

	p1->pos.x += offset.x;
	p1->pos.y += offset.y;

	p2->pos.x -= offset.x;
	p2->pos.y -= offset.y;
}

void stick::draw(renderer& r)
{
	r.drawn_line(p1->pos.x, p1->pos.y, p2->pos.x, p2->pos.y, 0xFF0048E3);
}