#ifndef MENUCOMPONENT_H
#define MENUCOMPONENT_H

#include <string>
// #include <MenuComponentAction.h>

// defining the component action here avoids the have not been declared
// error that is triggered because of the circular dependency between
// menuComponent and MenuComponentAction.
class MenuComponentAction;

class MenuComponent
{
    public:
        MenuComponent();
        virtual ~MenuComponent();

        virtual std::string getLabel() = 0;

        virtual void addAction(MenuComponentAction* action) = 0;

        virtual void executeAction() = 0;

    protected:

    private:
};

#endif // MENUCOMPONENT_H
