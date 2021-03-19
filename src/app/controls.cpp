#include "..\Engine\window.h"

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