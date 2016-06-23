#include "MenuComponent.h"
#include <string>

MenuComponent::MenuComponent()
{
    //ctor
}

MenuComponent::~MenuComponent()
{
    //dtor
}

void MenuComponent::add(MenuComponent* item)
{
  item->setParent(this);
  this->items.push_back(item);
}

std::string MenuComponent::getLabel()
{
  return this->label;
}

void MenuComponent::addAction(MenuComponentAction* action)
{
  this->actions.push_back(action);
}

void MenuComponent::executeActions()
{
  for (unsigned int i = 0; i < this->actions.size(); i++)
  {
    this->actions[i]->execute(this);
  }
}

MenuComponent* MenuComponent::getParent()
{
  return this->parent;
}

void MenuComponent::setParent(MenuComponent* parent)
{
  this->parent = parent;
}

MenuSDLRenderer* MenuComponent::getRenderer()
{
  return this->renderer;
}

void MenuComponent::setRenderer(MenuSDLRenderer* renderer)
{
  this->renderer = renderer;
}

void MenuComponent::enableEvents()
{
  this->areEventsDisabled = false;
}

void MenuComponent::disableEvents()
{
  this->areEventsDisabled = true;
}



