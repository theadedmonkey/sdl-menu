#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>
#include <vector>

#include <MenuComponent.h>
#include <MenuComponentAction.h>

class MenuItem : public MenuComponent
{
    public:
        MenuItem();
        MenuItem(std::string label);
        virtual ~MenuItem();

        std::string getLabel();
        void addAction(MenuComponentAction* action);
        void executeAction();

    protected:

    private:
      std::string label;
      std::vector<MenuComponentAction*> actions;
};

#endif // MENUITEM_H
