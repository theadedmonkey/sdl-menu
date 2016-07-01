#include "../include/MenuItem.h"

MenuItem::MenuItem()
{

}

MenuItem::MenuItem(
  SDL_Renderer* renderer_sdl,
  std::string label,
  Style* style_default,
  Style* style_hover
) : m_renderer_sdl(renderer_sdl),
    m_label(label),
    m_style(style_default),
    m_style_default(style_default),
    m_style_hover(style_hover)
{
  m_font = createFont(m_font_path, m_style_default->fontSize);

  m_texture_label = createTextTexture(
    m_renderer_sdl,
    m_label,
    m_font,
    m_style_default->fontColor
  );

  m_rect_src_label = createRectFromTexture(m_texture_label);
  m_rect_dst_label = m_rect_src_label;
  m_rect_dst_label.x = m_style_default->x;
  m_rect_dst_label.y = m_style_default->y;

  m_rect_background = m_rect_dst_label;
  m_rect_background.w += m_style_default->padding * 2;
  m_rect_background.h += m_style_default->padding * 2;

  m_rect_dst_label.x = m_rect_background.x + m_style_default->padding;
  m_rect_dst_label.y = m_rect_background.y + m_style_default->padding;

  //bounds
  m_min_x = m_rect_background.x;
  m_min_y = m_rect_background.y;
  m_max_x = m_min_x + m_rect_background.w;
  m_max_y = m_min_y + m_rect_background.h;
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
  SDL_RenderCopy(m_renderer_sdl, m_texture_label, &m_rect_src_label, &m_rect_dst_label);
}

void MenuItem::processEvent(SDL_Event* event)
{
  if(event->type == SDL_MOUSEMOTION ||
     event->type == SDL_MOUSEBUTTONDOWN ||
     event->type == SDL_MOUSEBUTTONUP)
    {
      int mouse_x, mouse_y;
      SDL_GetMouseState(&mouse_x, &mouse_y);

      bool isInside = true;
      if (mouse_x < m_min_x ||
          mouse_x > m_max_x ||
          mouse_y < m_min_y ||
          mouse_y > m_max_y)
      {
        isInside = false;
      }

      if (isInside)
      {
        switch(event->type)
        {
          case SDL_MOUSEBUTTONDOWN:
          std::cout << "clicked" << std::endl;
          break;

          case SDL_MOUSEMOTION:
          m_style = m_style_hover;
          break;
        }
      }
      else
      {
        switch(event->type)
        {
          case SDL_MOUSEMOTION:
          m_style = m_style_default;
          break;
        }  
      }
    }
}
