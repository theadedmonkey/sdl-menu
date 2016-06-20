#ifndef ACTIONPRINTLABEL_H
#define ACTIONPRINTLABEL_H

#include <MenuComponent.h>
#include <MenuComponentAction.h>

class ActionPrintLabel : public MenuComponentAction
{
  public:
    ActionPrintLabel();
    virtual ~ActionPrintLabel();

    void execute(MenuComponent* target);

  protected:

  private:
};

#endif // ACTIONPRINTLABEL_H
