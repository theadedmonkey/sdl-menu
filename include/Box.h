#ifndef BOX_H
#define BOX_H

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "./Bounds.h"
#include "./Utils.h"

/*
 * TODO:
 * move the props interface to a struct called style,
 * box objects should suscribe to this struct in order
 * to listen to changes in the style an update properly
 *
 * the style struct props interface should be easy to use,
 * will be nice to use a fluid generic interface like
 * get("prop_name") and set("prop_name", prop_value)
 *
 * boxes are composable, each box can have one and only one
 * parent box where it inherits its props
 *
 * boxes can have a fixed size or and auto size, the auto
 * size is worked out by taking the maximun width and height
 * of all his children.
 *
 * boxes are formed by a rect that depicts the size of the box
 * and its boundaries (min_x, max_y ...)
 *
 * boxes can have additional rects depicting the background, borders ...
 *
 * boxes have the notion of editable area, this area is where the children
 * will be rendered inside the box, the origin of this area is determined
 * by the padding and border of the box.
 */
class Box
{
    public:
        Box();
        Box(SDL_Renderer* renderer_sdl);
        virtual ~Box();

        int getX();
        void setX(int x);

        int getY();
        void setY(int y);

        int getW();
        void setW(int w);

        int getH();
        void setH(int h);

        int getPadding();
        void setPadding(int padding);

        SDL_Color getBackgroundColor();
        void setBackgroundColor(SDL_Color background_color);

        std::string getFontName();
        void setFontName(std::string font_name);

        SDL_Color getFontColor();
        void setFontColor(SDL_Color font_color);

        int getFontSize();
        void setFontSize(int font_size);

        void render();

    protected:
    private:
      SDL_Renderer* m_renderer_sdl;
      SDL_Rect      m_rect = { 0, 0, 0, 0 };
      SDL_Texture*  m_texture;
      //bounds
      int m_min_x = 0;
      int m_min_y = 0;
      int m_max_x = 0;
      int m_max_y = 0;
      // props
      int m_padding = 0;

      SDL_Color m_background_color = { 255, 255, 255, 255 };

      std::string m_font_name = "";
      SDL_Color m_font_color = { 255, 255, 255, 255 };
      int m_font_size = 16;
};


#endif // BOX_H
