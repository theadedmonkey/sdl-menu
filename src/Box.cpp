#include "../include/Box.h"

Box::Box() {}

Box::Box(
  SDL_Renderer* renderer_sdl
) : m_renderer_sdl(renderer_sdl) {}

Box::~Box() {}

int Box::getX() { return m_rect.x; }
void Box::setX(int x)
{
  m_rect.x = x;
  // update bounds
  m_min_x = x;
  m_max_x = m_min_x + m_rect.w;
}

int Box::getY() { return m_rect.y; }
void Box::setY(int y)
{
  m_rect.y = y;
  // update bounds
  m_min_y = y;
  m_max_y = m_min_y + m_rect.h;
}

int Box::getW() { return m_rect.w; }
void Box::setW(int w)
{
  m_rect.w = w;
  // update bounds
  m_max_x = m_min_x + w;
}

int Box::getH() { return m_rect.h; }
void Box::setH(int h) {
  m_rect.h = h;
  // update bounds
  m_max_y = m_min_y + h;
}

int Box::getPadding() { return m_padding; }
void Box::setPadding(int padding)
{
  m_padding = padding;
  setW(m_rect.w + padding * 2);
  setH(m_rect.h + padding * 2); 
}

SDL_Color Box::getBackgroundColor() { return m_background_color; }
void Box::setBackgroundColor(SDL_Color background_color) { m_background_color = background_color; }

std::string Box::getFontName() { return m_font_name; }
void Box::setFontName(std::string font_name) { m_font_name = font_name; }

SDL_Color Box::getFontColor() { return m_font_color; }
void Box::setFontColor(SDL_Color font_color) { m_font_color = font_color; }

int Box::getFontSize() { return m_font_size; }
void Box::setFontSize(int font_size) { m_font_size = font_size; }


void Box::render()
{
  SDL_SetRenderDrawColor(
    m_renderer_sdl,
    m_background_color.r,
    m_background_color.g,
    m_background_color.b,
    m_background_color.a
  );
  SDL_RenderFillRect(m_renderer_sdl, &m_rect);
}
