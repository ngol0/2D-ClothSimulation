#include <iostream>
#include "app.h"
#include "global/vec2.h"

void application::set_up()
{
	m_is_running = m_renderer.set_up();
	m_last_update_frame = SDL_GetTicks();

	float cloth_width = 1200.f;
	float cloth_height = 320.f;
	float cloth_spacing = 10.f;

	float startX = m_renderer.get_win_width() * 0.5f - (cloth_width/cloth_spacing) * cloth_spacing * 0.5f;
	float startY = m_renderer.get_win_height() * 0.1f;
	m_cloth.init(vec2(startX, startY), vec2(cloth_width, cloth_height), cloth_spacing);

	//m_rect.init(m_renderer);
}

void application::input()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_is_running = false;
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				m_is_running = false;
			}
			break;
		}
	}
}

void application::update()
{
	Uint32 currentTime = SDL_GetTicks();
	float deltaTime = (currentTime - m_last_update_frame) / 1000.0f;

	m_cloth.update(deltaTime, m_renderer);
	//m_rect.update(deltaTime, m_renderer);

	m_last_update_frame = currentTime;
}

void application::render()
{
	m_renderer.clear_screen(0xFF000816);

	m_cloth.draw(m_renderer);
	//m_rect.draw(m_renderer);

	m_renderer.draw();
}


void application::shutdown()
{
	
}
