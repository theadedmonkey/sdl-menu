#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "./Bounds.h"
#include "./Style.h"
#include "./Utils.h"
#include "./MenuItem.h"

class Menu
{
    public:
        Menu();
        Menu(
          SDL_Renderer* renderer_sdl,
          std::string label,
          Style style_items,
          Style style_items_hover
        );
        virtual ~Menu();

        void add(std::string label);

        void render();
        void processEvent(SDL_Event* event);

    protected:
    private:
      std::string m_label = "";
      SDL_Renderer* m_renderer_sdl;
      // style
      Style m_style_items;
      Style m_style_items_hover;

      std::vector<MenuItem*> m_items;
};

#endif // MENU_H
