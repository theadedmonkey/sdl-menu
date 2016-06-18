#include "MenuItem.h"
#include <string>

MenuItem::MenuItem()
{
    //ctor
}

MenuItem::~MenuItem()
{
    //dtor
}

MenuItem::MenuItem(std::string label)
{
  this->label = label;
}

std::string MenuItem::getLabel()
{
  return this->label;
}
