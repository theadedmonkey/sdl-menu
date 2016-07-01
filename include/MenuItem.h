#ifndef MENUITEM_H
#define MENUITEM_H

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "./Style.h"
#include "./Utils.h"

class MenuItem
{
    public:
        MenuItem();
        MenuItem(
          SDL_Renderer* renderer,
          std::string label,
          Style* style_default,
          Style* style_hover
        );
        virtual ~MenuItem();

        std::string getLabel();
        void setLabel(std::string label);

        void render();
        void processEvent(SDL_Event* event);

    protected:
    private:
      std::string m_label = "";
      SDL_Renderer* m_renderer_sdl;
      // style
      Style*        m_style;
      Style*        m_style_default;
      Style*        m_style_hover;
      // bounds
      int m_min_x = 0;
      int m_min_y = 0;
      int m_max_x = 0;
      int m_max_y = 0;
      // rects
      SDL_Rect      m_rect_src_label;
      SDL_Rect      m_rect_dst_label;
      SDL_Rect      m_rect_background;
      // textures
      SDL_Texture*  m_texture_label;
      // SDL_Texture*  m_texture_background;
      // font
      std::string   m_font_dir = "../assets/";
      std::string   m_font_path = m_font_dir + m_style->fontName;
      TTF_Font*     m_font;
};

#endif // MENUITEM_H
