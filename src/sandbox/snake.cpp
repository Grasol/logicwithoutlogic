#include "snake.h"

extern int g_window_width, g_window_height;

Snake::Snake(int x, int y, int w, int h, float speed, Direction dir)
	: m_x(x), m_y(y), m_w(w), m_h(h), m_speed(speed)
{
	posLimit();
	setDirection(dir);
}

Snake::~Snake()
{
}

void Snake::setDirection(Direction dir)
{
	if (dir == Direction::UP)
	{
		if (!(m_movement[1] == -1))
		{
			m_movement = {0, 1};
		}
	}
	if (dir == Direction::DOWN)
	{
		if (!(m_movement[1] == 1))
		{
			m_movement = {0, -1};
		}
	}
	if (dir == Direction::LEFT)
	{
		if (!(m_movement[0] == 1))
		{
			m_movement = {-1, 0};
		}
	}
	if (dir == Direction::RIGHT)
	{
		if (!(m_movement[0] == -1))
		{
			m_movement = {1, 0};
		}
	}
}

void Snake::move(Rect& rect)
{
	if (m_movement[1] == 1)
	{
		m_y -= m_speed;
	}
	if (m_movement[1] == -1)
	{
		m_y += m_speed;
	}
	if (m_movement[0] == -1)
	{
		m_x -= m_speed;
	}
	if (m_movement[0] == 1)
	{
		m_x += m_speed;
	}

	posLimit();

	correctPos(rect);
}

void Snake::posLimit()
{
	if ((int)m_x >= g_window_width)
		m_x = 0;

	if ((int)m_y >= g_window_height)
		m_y = 0;

	if (m_x < 0)
		m_x = (float)g_window_width;

	if (m_y < 0)
		m_y = (float)g_window_height;
}

void Snake::correctPos(Rect& rect)
{
	float fx, fy;
	fx = m_x / m_w;
	fy = m_y / m_h;
	rect.changeXY((int)fx * m_w, (int)fy * m_h);
}

void Snake::moveTail()
{

}