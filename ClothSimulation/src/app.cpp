#include <iostream>
#include "app.h"

void application::set_up()
{
	m_is_running = m_renderer.set_up();
	m_last_update_frame = SDL_GetTicks();

	m_rect.init(m_renderer);
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

	m_rect.update(deltaTime, m_renderer);

	m_last_update_frame = currentTime;
}

void application::render()
{
	m_renderer.clear_screen(0xFF000816);
	m_rect.draw(m_renderer);
	m_renderer.draw();
}


void application::shutdown()
{
	
}
