#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>
#include <MenuComponent.h>

class MenuItem : public MenuComponent
{
    public:
        MenuItem();
        MenuItem(std::string label);
        virtual ~MenuItem();

        std::string getLabel();

    protected:

    private:
      std::string label;
};

#endif // MENUITEM_H
