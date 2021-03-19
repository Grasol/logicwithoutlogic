#include "renderer.h"

Rect::Rect(const Window& window, int x, int y, int w, int h, int R, int G, int B, int A)
	: Window(window), m_x(x), m_y(y), m_w(w), m_h(h), m_R(R), m_G(G), m_B(B), m_A(A)
{

}

Rect::~Rect()
{

}

void Rect::changeXY(int x, int y)
{
	m_x = x;
	m_y = y;
}

void Rect::draw() const
{
	SDL_Rect rect = {m_x, m_y, m_w, m_h};

	SDL_SetRenderDrawColor(m_renderer, m_R, m_G, m_B, m_A);
	SDL_RenderFillRect(m_renderer, &rect);
}