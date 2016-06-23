#include "ActionSwicthMenu.h"

#include <iostream>

ActionSwicthMenu::ActionSwicthMenu()
{
    //ctor
}

ActionSwicthMenu::ActionSwicthMenu(Menu* menu)
{
  this->menu = menu;
}

ActionSwicthMenu::~ActionSwicthMenu()
{
    //dtor
}

void ActionSwicthMenu::execute(MenuComponent* target)
{
  MenuComponent* parent = target->getParent();

  parent->disableEvents();
  this->menu->enableEvents();

  parent->getRenderer()->setMenu(this->menu);
}
