#include <iostream>
#include "renderer.h"

bool renderer::set_up()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cerr << "Error initializing SDL" << std::endl;
		return false;
	}

	SDL_DisplayMode displayMode;
	SDL_GetCurrentDisplayMode(0, &displayMode);
	windowWidth = displayMode.w;
	windowHeight = displayMode.h;

	m_window = SDL_CreateWindow(NULL, 0, 0, windowWidth, windowHeight, SDL_WINDOW_BORDERLESS);
	if (!m_window)
	{
		std::cerr << "Error initializing SDL window" << std::endl;
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!m_renderer)
	{
		std::cerr << "Error initializing SDL renderer" << std::endl;
		return false;
	}

	return true;
}

renderer::~renderer()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void renderer::clear_screen(Uint32 color) const
{
	SDL_SetRenderDrawColor(m_renderer, color >> 16, color >> 8, color, 255);
	SDL_RenderClear(m_renderer);
}

void renderer::draw() const
{
	SDL_RenderPresent(m_renderer);
}

void renderer::drawn_line(int x0, int y0, int x1, int y1, Uint32 color) const
{
	SDL_SetRenderDrawColor(m_renderer, color >> 16, color >> 8, color, 255);
	SDL_RenderDrawLine(m_renderer, x0, y0, x1, y1);
}

void renderer::drawn_point(int x, int y, Uint32 color) const
{
	SDL_SetRenderDrawColor(m_renderer, color >> 16, color >> 8, color, 255);
	SDL_RenderDrawPoint(m_renderer, x, y);
}