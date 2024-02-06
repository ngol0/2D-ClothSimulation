#pragma once

struct particle;
class renderer;

struct stick
{
	stick() {};
	stick(particle& p1, particle& p2, float length);

	particle* p1{nullptr};
	particle* p2{nullptr};
	float length{ 0.f };

	void update(float deltaTime);
	void draw(renderer& r);
};