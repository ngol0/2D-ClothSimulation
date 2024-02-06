#pragma once
#include <SDL.h>

struct point;
class renderer;

struct cloth_stick
{
private:
	bool b_selected{ false };
	bool b_alive{ true };

	point* p1{ nullptr };
	point* p2{ nullptr };
	float length{ 0.f };

	Uint32 m_selected_color = 0xfc036f;
	Uint32 m_cloth_color = 0xfcba03;

public:
	cloth_stick() {};
	cloth_stick(point& p1, point& p2, float length);

	void update(float deltaTime);
	void draw(renderer& r);
	void tear();

	void set_selected(bool state) { b_selected = state; }
};