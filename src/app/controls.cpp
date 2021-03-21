#include "window.h"

// Module to create controls
void keyPressed(Window* window, SDL_Keycode key)
{	
	switch (key)
	{
	case SDLK_ESCAPE:
		window->close();

	default:
		break;
	}
}