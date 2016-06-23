#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>

#include <MenuComponent.h>
#include <MenuComponentAction.h>
#include <MenuItem.h>

#include <SDL2/SDL.h>

class Menu: public MenuComponent
{
    public:
        Menu();
        virtual ~Menu();

        MenuComponent* getItem(int index);
        int getItemCount();
        MenuComponent* findItem(std::string label);

        int getIndex(std::string label);

        int getSelectedItemIndex();

        void processEvent(SDL_Event event);

    protected:

    private:

      int selectedItemIndex = 0;

      void selectNextItem();
      void selectPrevItem();

};

#endif // MENU_H
