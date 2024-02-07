#pragma once
#include <SDL.h>

struct point;
class renderer;

struct cloth_stick
{
private:
	bool b_selected{ false };
	bool b_alive{ true };

	point* m_p1{ nullptr };
	point* m_p2{ nullptr };
	float m_length{ 0.f };
	float m_distance_to_tear{ 50.f };

	Uint32 m_selected_color = 0xfc036f;
	Uint32 m_cloth_color = 0xfcba03;

public:
	cloth_stick() {};
	cloth_stick(point& m_p1, point& m_p2, float m_length);

	void update(float deltaTime);
	void draw(renderer& r);
	void tear();

	void set_selected(bool state) { b_selected = state; }
};