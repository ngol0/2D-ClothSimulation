#pragma once
#include <vector>
#include <SDL.h>
#include "renderer.h"
#include "cloth/cloth.h"
//#include "rect.h"

class application
{
private:
	renderer m_renderer;
	//rect m_rect;
	cloth m_cloth;

	bool m_is_running = false;
	Uint32 m_last_update_frame;

public:
	application() = default;
	~application() = default;

	bool is_running() const { return m_is_running; };

	void set_up();
	void input();

	void update();
	void render();
	void shutdown();
};
