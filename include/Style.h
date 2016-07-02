#ifndef STYLE_H
#define STYLE_H

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// refactor this to a more generic interface,
// it will be nice to have a fuild interface
// with two methods, get(property_name) and
// set(property_name, value)
class Style
{
    public:
        Style();
        virtual ~Style();

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

    protected:
    private:
      int m_x = 0;
      int m_y = 0;
      int m_w = 0;
      int m_h = 0;

      int m_padding = 0;

      SDL_Color m_background_color = { 255, 255, 255, 255 };

      std::string m_font_name = "";
      SDL_Color m_font_color = { 255, 255, 255, 255 };
      int m_font_size = 16;
};


#endif // STYLE_H
