#pragma once
#include <string>

#include "SDL2/SDL.h"

class Window
{
public:
	Window(const std::string& title, int width, int height);
	~Window();

	void pollEvents();
	void clear() const;

	inline void close() { m_closed = true; }
	inline bool isClosed() const { return m_closed; };

private:
	bool init();

private:
	std::string m_title = "Default Title";
	int m_width = 700;
	int m_height = 500;

	bool m_closed = false;

	SDL_Window* m_window = nullptr;

protected:
	SDL_Renderer* m_renderer = nullptr;
};