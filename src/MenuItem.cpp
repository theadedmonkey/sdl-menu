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
  m_font = createFont(m_font_path, m_style_default->getFontSize());

  m_texture_label = createTextTexture(
    m_renderer_sdl,
    m_label,
    m_font,
    m_style_default->getFontColor()
  );

  m_rect_src_label = createRectFromTexture(m_texture_label);
  m_rect_dst_label = m_rect_src_label;
  m_rect_dst_label.x = m_style_default->getX();
  m_rect_dst_label.y = m_style_default->getY();

  m_rect_background = m_rect_dst_label;
  m_rect_background.w += m_style_default->getPadding() * 2;
  m_rect_background.h += m_style_default->getPadding() * 2;

  m_rect_dst_label.x = m_rect_background.x + m_style_default->getPadding();
  m_rect_dst_label.y = m_rect_background.y + m_style_default->getPadding();

  //bounds
  m_bounds.min_x = m_rect_background.x;
  m_bounds.min_y = m_rect_background.y;
  m_bounds.max_x = m_bounds.min_x + m_rect_background.w;
  m_bounds.max_y = m_bounds.min_y + m_rect_background.h;
}

MenuItem::~MenuItem() { }

std::string MenuItem::getLabel() { return m_label; }
void MenuItem::setLabel(std::string label) { m_label = label; }

Style* MenuItem::getStyleDefault() { return m_style_default; }
Style* MenuItem::getStyleHover() { return m_style_hover; }

Bounds* MenuItem::getBounds() { return &m_bounds; }

void MenuItem::render()
{
  // set background color
  SDL_SetRenderDrawColor(
    m_renderer_sdl,
    m_style->getBackgroundColor().r,
    m_style->getBackgroundColor().g,
    m_style->getBackgroundColor().b,
    m_style->getBackgroundColor().a
  );
  // render background
  SDL_RenderFillRect(m_renderer_sdl, &m_rect_background);
  // set label color
  SDL_SetRenderDrawColor(
    m_renderer_sdl,
    m_style->getFontColor().r,
    m_style->getFontColor().g,
    m_style->getFontColor().b,
    m_style->getFontColor().a
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
      if (mouse_x < m_bounds.min_x ||
          mouse_x > m_bounds.max_x ||
          mouse_y < m_bounds.min_y ||
          mouse_y > m_bounds.max_y)
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
