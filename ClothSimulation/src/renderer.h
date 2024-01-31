#pragma once
#include <SDL.h>

class renderer 
{
private:
	int windowWidth, windowHeight;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

public:
	renderer() = default;
	~renderer();

	int get_win_width() const { return windowWidth; }
	int get_win_height() const { return windowHeight; }

	bool set_up();

	void clear_screen(Uint32 color) const;
	void draw() const;

	void drawn_line(int x0, int y0, int x1, int y1, Uint32 color) const;
	void drawn_point(int x, int y, Uint32 color) const;
};