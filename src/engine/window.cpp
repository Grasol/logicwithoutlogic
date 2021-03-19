#include "window.h"

#include <iostream>

extern void keyPressed(Window*, SDL_Keycode);

Window::Window(const std::string& title, int width, int height)
	: m_title(title), m_width(width), m_height(height)
{
	m_closed = !init();
}

Window::~Window()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

// Returns true if initialized succesfully
bool Window::init()
{
	// Initializing SDL
	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		std::cerr << "SDL failed to initialize.\n";
		return false;
	}

	// Creates window
	m_window = SDL_CreateWindow(
		m_title.c_str(),				// Window title
		SDL_WINDOWPOS_CENTERED,			// Window pos
		SDL_WINDOWPOS_CENTERED,			// Window pos
		m_width, m_height,				// Window width and heigth
		0								// Flags
	);

	if (m_window == nullptr)
	{
		std::cerr << "Failed to create window.\n";
		return false;
	}

	// Creates renderer
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

	if (m_renderer == nullptr)
	{
		std::cerr << "Failed to create renderer.\n";
		return false;
	}

	return true;
}

void Window::pollEvents()
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_closed = true;
			break;
		
		case SDL_KEYDOWN:
			keyPressed(this, event.key.keysym.sym);
			break;

		default:
			break;
		}
	}
}

void Window::clear() const
{
	SDL_RenderPresent(m_renderer);
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_renderer);
}