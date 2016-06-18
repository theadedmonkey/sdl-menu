#ifndef MENUCOMPONENT_H
#define MENUCOMPONENT_H

#include <string>

class MenuComponent
{
    public:
        MenuComponent();
        virtual ~MenuComponent();

        virtual std::string getLabel() = 0;

    protected:

    private:
};

#endif // MENUCOMPONENT_H
