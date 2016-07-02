#include "../include/Menu.h"

Menu::Menu()
{

}

Menu::Menu(
  SDL_Renderer* renderer_sdl,
  std::string label,
  Style* style_items,
  Style* style_items_hover
) : m_renderer_sdl(renderer_sdl),
    m_label(label),
    m_style_items(style_items),
    m_style_items_hover(style_items_hover)
{

}

Menu::~Menu()
{

}

void Menu::addItem(std::string label)
{
  Style* style_default = m_style_items;

  MenuItem* prev_item;
  Bounds*   prev_item_bounds;
  // works out the position of the new menu item
  // using the position of the previous item in the
  // menu
  if (m_items.size())
  {
    prev_item = m_items.back();
    prev_item_bounds = prev_item->getBounds();

    style_default->setX(prev_item_bounds->min_x);
    style_default->setY(prev_item_bounds->max_y);

    m_items.push_back(new MenuItem(
      m_renderer_sdl,
      label,
      style_default,
      m_style_items_hover
    ));
  }
  else
  {
    m_items.push_back(new MenuItem(
      m_renderer_sdl,
      label,
      style_default,
      m_style_items_hover
    ));
  }
}

void Menu::render()
{
  for (auto i = 0; i < m_items.size(); i++)
  {
    m_items[i]->render();
  }
}

void Menu::processEvent(SDL_Event* event)
{
  for (auto i = 0; i < m_items.size(); i++)
  {
    m_items[i]->processEvent(event);
  }
}
