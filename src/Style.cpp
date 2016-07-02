#include "../include/Style.h"

Style::Style()
{

}

Style::~Style()
{

}

int Style::getX() { return m_x; }
void Style::setX(int x) { m_x = x; }

int Style::getY() { return m_y; }
void Style::setY(int y) { m_y = y; }

int Style::getW() { return m_w; }
void Style::setW(int w) { m_w = w; }

int Style::getH() { return m_h; }
void Style::setH(int h) { m_h = h; }

int Style::getPadding() { return m_padding; }
void Style::setPadding(int padding) { m_padding = padding; }

SDL_Color Style::getBackgroundColor() { return m_background_color; }
void Style::setBackgroundColor(SDL_Color background_color) { m_background_color = background_color; }

std::string Style::getFontName() { return m_font_name; }
void Style::setFontName(std::string font_name) { m_font_name = font_name; }

SDL_Color Style::getFontColor() { return m_font_color; }
void Style::setFontColor(SDL_Color font_color) { m_font_color = font_color; }

int Style::getFontSize() { return m_font_size; }
void Style::setFontSize(int font_size) { m_font_size = font_size; }
