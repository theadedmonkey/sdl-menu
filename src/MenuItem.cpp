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

MenuItem::MenuItem(std::string label)
{
  this->label = label;
}

void MenuItem::processEvent(SDL_Event event)
{

}
