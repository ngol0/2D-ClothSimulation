#pragma once

struct point;
class renderer;

struct stick
{
	stick() {};
	stick(point& p1, point& p2, float length);

	point* p1{nullptr};
	point* p2{nullptr};
	float length{ 0.f };

	void update(float deltaTime);
	void draw(renderer& r);
};