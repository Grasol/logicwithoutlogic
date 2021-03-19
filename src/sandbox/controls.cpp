#include "..\Engine\window.h"

#include "snake.h"

extern Snake g_snake;

void keyPressed(Window* window, SDL_Keycode key)
{	
	switch (key)
	{
	case SDLK_ESCAPE:
		window->close();

	case SDLK_UP:
	case SDLK_w:
		g_snake.setDirection(Direction::UP);
		break;

	case SDLK_DOWN:
	case SDLK_s:
		g_snake.setDirection(Direction::DOWN);
		break;

	case SDLK_LEFT:
	case SDLK_a:
		g_snake.setDirection(Direction::LEFT);
		break;

	case SDLK_RIGHT:
	case SDLK_d:
		g_snake.setDirection(Direction::RIGHT);
		break;
		
	default:
		break;
	}
}