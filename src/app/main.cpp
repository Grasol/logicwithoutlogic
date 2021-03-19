#include "window.h"
#include "renderer.h"

// Window properties
int g_window_width = 1000;
int g_window_height = 800;

// Main function
int main(int argc, char const *argv[])
{
    // Creates window
    Window main_window("May the logic be with you", g_window_width, g_window_height);
    Rect rect(main_window, g_window_width/2, g_window_height/2, 100, 100, 255, 0, 15, 200);

    // Loop goes on until the window is closed
	while (!main_window.isClosed())
	{
		rect.draw();
		main_window.pollEvents();
		main_window.clear();
	}

    return 0;
}
/* TROLOLOLO HAHAHAHAHA
 * 
 * Pisze w UTF-8 btw, ale itak polskich znaków bedziemy unikać raczej narazie
 * Traz teraz ogarnąć ustawienia dla linkera żeby to skubaniec kompilował dobrze
 * 
 * 
 * 
 */