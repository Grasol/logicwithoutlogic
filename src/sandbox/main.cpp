#include "..\Engine\window.h"
#include "..\Engine\renderer.h"
#include "snake.h"
#include <random>

// Settings
int g_fps = 8;
unsigned int g_score = 0;
static int grid[2] = {40, 20};



static int randomInt(int rangea, int rangeb);

// Global variables
int g_window_width = grid[0] * 10;
int g_window_height = grid[1] * 10;
static float snake_speed = g_fps / (60.0f / 10);
Snake g_snake(randomInt(0, g_window_width), randomInt(0, g_window_height), 10, 10, snake_speed, Direction::DOWN);

int main(int argc, char** argv)
{
	// Creates window
	Window window("Snake", g_window_width, g_window_height);
	Rect rect(window, (int)g_snake.getPosX(), (int)g_snake.getPosY(), g_snake.getWidth(), g_snake.getHeight(), 255, 255, 255, 255);

	// Loop goes on until the window is closed
	while (!window.isClosed())
	{
		g_snake.move(rect);
		rect.draw();
		window.pollEvents();
		window.clear();
	}

	return 0;
}

static int randomInt(int rangea, int rangeb)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(rangea, rangeb);

	return dist(mt);
}