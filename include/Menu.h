#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>

#include <SDL2/SDL.h>

#include <MenuComponent.h>
#include <MenuItem.h>

class Menu: public MenuComponent
{
    public:
        Menu();
        virtual ~Menu();

        void add(std::string label);
        MenuComponent* getItem(int index);
        int getItemCount();
        MenuComponent* findItem(std::string label);

        std::string getLabel();
        int getIndex(std::string label);

        int getSelectedItemIndex();

        void processEvent(SDL_Event event);

    protected:

    private:
      std::vector<MenuComponent*> items;
      int selectedItemIndex = 0;

      void selectNextItem();
      void selectPrevItem();

};

#endif // MENU_H
