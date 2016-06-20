#ifndef MENUCOMPONENTACTION_H
#define MENUCOMPONENTACTION_H

#include <MenuComponent.h>

class MenuComponentAction
{
  public:
    MenuComponentAction();
    virtual ~MenuComponentAction();

    virtual void execute(MenuComponent* target) = 0;

  protected:

  private:
};

#endif // MENUCOMPONENTACTION_H
