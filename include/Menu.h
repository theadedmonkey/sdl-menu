#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>

#include <SDL2/SDL.h>

#include <MenuComponent.h>
#include <MenuComponentAction.h>
#include <MenuItem.h>

class Menu: public MenuComponent
{
    public:
        Menu();
        virtual ~Menu();

        void add(std::string label);
        void add(MenuComponent* item);
        MenuComponent* getItem(int index);
        int getItemCount();
        MenuComponent* findItem(std::string label);

        std::string getLabel();
        int getIndex(std::string label);

        int getSelectedItemIndex();

        void processEvent(SDL_Event event);

        void addAction(MenuComponentAction* action);
        void executeAction();

    protected:

    private:
      std::vector<MenuComponent*> items;
      int selectedItemIndex = 0;

      void selectNextItem();
      void selectPrevItem();

};

#endif // MENU_H
