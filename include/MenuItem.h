#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>
#include <vector>

#include <MenuComponent.h>
#include <MenuComponentAction.h>

#include <SDL2/SDL.h>

class MenuItem : public MenuComponent
{
    public:
        MenuItem();
        MenuItem(std::string label);
        virtual ~MenuItem();

        void processEvent(SDL_Event event);
    protected:

    private:

};

#endif // MENUITEM_H
