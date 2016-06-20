#include "MenuItem.h"
#include <string>
#include <MenuComponentAction.h>

MenuItem::MenuItem()
{
    //ctor
}

MenuItem::~MenuItem()
{
    //dtor
}

void MenuItem::addAction(MenuComponentAction* action)
{
  this->actions.push_back(action);
}

MenuItem::MenuItem(std::string label)
{
  this->label = label;
}

std::string MenuItem::getLabel()
{
  return this->label;
}

void MenuItem::executeAction()
{
  for (int i = 0; i < this->actions.size(); i++)
  {
    this->actions[i]->execute(this);
  }
}
