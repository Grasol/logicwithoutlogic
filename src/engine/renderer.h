#pragma once
#include "window.h"

class Rect : public Window
{
public:
	Rect(const Window& window, int x, int y, int w, int h, int R, int G, int B, int A);
	~Rect();

	void changeXY(int x, int y);
	void draw() const;

private:
	int m_x, m_y;
	int m_w, m_h;
	int m_R, m_G, m_B, m_A;
};