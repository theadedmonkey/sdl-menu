#ifndef ACTIONSWICTHMENU_H
#define ACTIONSWICTHMENU_H

#include <MenuComponent.h>
#include <MenuComponentAction.h>
#include <MenuSDLRenderer.h>
#include <Menu.h>


class ActionSwicthMenu: public MenuComponentAction
{
    public:
        ActionSwicthMenu();
        ActionSwicthMenu(Menu* menu);
        virtual ~ActionSwicthMenu();

        void execute(MenuComponent* target);
    protected:
    private:
      Menu* menu;
};

#endif // ACTIONSWICTHMENU_H
