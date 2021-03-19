#pragma once
#include <string>
#include <array>

#include "..\Engine\renderer.h"

enum class Direction
{
	UP, DOWN, LEFT, RIGHT
};

class Snake
{
public:
	Snake(int x, int y, int w, int h, float speed, Direction dir);
	~Snake();

	void setDirection(Direction dir);
	void move(Rect& rect);

	inline int getPosX() const { return m_x; };
	inline int getPosY() const { return m_y; };
	inline int getWidth() const { return m_w; };
	inline int getHeight() const { return m_h; };

private:
	void posLimit();
	void correctPos(Rect& rect);
	void moveTail();

private:
	float m_x, m_y;									// x & y coordinate
	int m_w, m_h;									// width & height of snake's body
	float m_speed;

	std::array<int, 2> m_movement = {0, 0};			// left/rigth, up/down
	
	int tail = 0;
};