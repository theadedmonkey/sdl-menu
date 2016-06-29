#include "../include/MenuItem.h"

MenuItem::MenuItem()
{

}

MenuItem::MenuItem(
  SDL_Renderer* renderer_sdl,
  std::string label,
  Style* style
) : m_renderer_sdl(renderer_sdl), m_label(label), m_style(style)
{
  m_font = createFont(m_font_path, m_style->fontSize);

  m_texture_label = createTextTexture(
    m_renderer_sdl,
    m_label,
    m_font,
    m_style->fontColor
  );

  m_rect_dst_label = createRectFromTexture(m_texture_label);
  m_rect_background = m_rect_dst_label;

}

MenuItem::~MenuItem()
{

}

std::string MenuItem::getLabel()
{
  return m_label;
}

void MenuItem::setLabel(std::string label)
{
  m_label = label;
}

void MenuItem::render()
{
  // set background color
  SDL_SetRenderDrawColor(
    m_renderer_sdl,
    m_style->backgroundColor.r,
    m_style->backgroundColor.g,
    m_style->backgroundColor.b,
    m_style->backgroundColor.a
  );
  // render background
  SDL_RenderFillRect(m_renderer_sdl, &m_rect_background);
  // set label color
  SDL_SetRenderDrawColor(
    m_renderer_sdl,
    m_style->fontColor.r,
    m_style->fontColor.g,
    m_style->fontColor.b,
    m_style->fontColor.a
  );
  // render label
  SDL_RenderCopy(m_renderer_sdl, m_texture_label, nullptr, &m_rect_dst_label);
}
