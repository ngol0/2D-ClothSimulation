#pragma once
#include "point.h"
#include "stick.h"

class renderer;

struct rect
{
	rect() {};
	point points[4];
	stick sticks[6];

	void init(renderer& renderer);
	void update(float deltaTime, renderer& renderer);
	void draw(renderer& renderer);
};