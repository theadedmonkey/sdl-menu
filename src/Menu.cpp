#include "Menu.h"

#include <iostream>
#include <string>
#include <algorithm>

#include <SDL2/SDL.h>

#include <MenuComponent.h>
#include <MenuComponentAction.h>
#include <MenuItem.h>

Menu::Menu()
{

}

Menu::~Menu()
{
    //dtor
}

int Menu::getIndex(std::string label)
{
  for (int i = 0 ; i < this->getItemCount(); i++)
  {
    if (this->items[i]->getLabel() == label)
    {
      return i;
    }
  }
  return -1;
}

MenuComponent* Menu::getItem(int index)
{
  return this->items[index];
}



int Menu::getItemCount()
{
    return this->items.size();
}

MenuComponent* Menu::findItem(std::string label)
{
  for (int i = 0; i < this->getItemCount(); i++)
  {
    if (this->items[i]->getLabel() == label)
    {
      return this->items[i];
    }
  }
  return nullptr;
}

int Menu::getSelectedItemIndex()
{
  return this->selectedItemIndex;
}

void Menu::processEvent(SDL_Event event)
{
  if (this->areEventsDisabled)
  {
    return;
  }

  if(event.type == SDL_KEYDOWN)
  {
    switch(event.key.keysym.sym)
    {
      case SDLK_UP:
        this->selectPrevItem();
        break;
      case SDLK_DOWN:
        this->selectNextItem();
        break;
      case SDLK_RETURN:
        this->items[this->getSelectedItemIndex()]->executeActions();
        break;
    }
  }
}

void Menu::selectNextItem()
{
  if (this->getSelectedItemIndex() + 1 >= this->getItemCount())
  {
    this->selectedItemIndex = 0;
  }
  else
  {
    this->selectedItemIndex += 1;
  }
}

void Menu::selectPrevItem()
{
  if (this->getSelectedItemIndex() - 1 < 0)
  {
    this->selectedItemIndex = this->getItemCount() - 1;
  }
  else
  {
    this->selectedItemIndex -= 1;
  }
}
