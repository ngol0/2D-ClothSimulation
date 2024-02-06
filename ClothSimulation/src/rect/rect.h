#pragma once
#include "particle.h"
#include "stick.h"

class renderer;

struct rect
{
	rect() {};
	particle points[4];
	stick sticks[6];

	void init(renderer& renderer);
	void update(float deltaTime, renderer& renderer);
	void draw(renderer& renderer);
};