#ifndef MENUCOMPONENT_H
#define MENUCOMPONENT_H

#include <string>
#include <vector>

#include <MenuComponentAction.h>

#include <SDL2/SDL.h>

// defining the component action here avoids the have not been declared
// error that is triggered because of the circular dependency between
// menuComponent and MenuComponentAction.
//class MenuComponentAction;

class MenuSDLRenderer;

class MenuComponent
{
    public:
        MenuComponent();
        virtual ~MenuComponent();

        void add(MenuComponent* item);
        std::string getLabel();

        void addAction(MenuComponentAction* action);
        void executeActions();

        virtual void processEvent(SDL_Event event) = 0;

        void enableEvents();
        void disableEvents();

        MenuComponent* getParent();
        void setParent(MenuComponent* parent);

        MenuSDLRenderer* getRenderer();
        void setRenderer(MenuSDLRenderer* renderer);

    protected:
      bool areEventsDisabled = false;
      MenuSDLRenderer* renderer;
      MenuComponent* parent = nullptr;
      std::vector<MenuComponent*> items;
      std::string label = "label";
      std::vector<MenuComponentAction*> actions;

    private:
};

#endif // MENUCOMPONENT_H
