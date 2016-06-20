#include "ActionPrintLabel.h"

#include <iostream>

#include <MenuComponent.h>
#include <MenuComponentAction.h>


ActionPrintLabel::ActionPrintLabel()
{
  //ctor
}

ActionPrintLabel::~ActionPrintLabel()
{
  //dtor
}

void ActionPrintLabel::execute(MenuComponent* target)
{
  std::cout << "label: " << target->getLabel() << std::endl;
}
