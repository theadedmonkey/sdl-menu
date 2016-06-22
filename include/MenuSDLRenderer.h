#ifndef MENUSDLRENDERER_H
#define MENUSDLRENDERER_H

#include <string>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <Menu.h>

class MenuSDLRenderer
{
  public:
    MenuSDLRenderer(Menu* menu, SDL_Renderer* renderer, int x = 0, int y = 0);
    virtual ~MenuSDLRenderer();

    void render();

    int getW();
    int getH();

    void setX(int x);
    void setY(int y);

  protected:

  private:
    Menu* menu;

    SDL_Renderer* renderer;

    // position
    int x, y;

    // label surface size
    struct labelSurfaceSize
    {
      std::string label;
      int w;
      int h;
    };

    labelSurfaceSize getLabelSurfaceSize(std::string label);

    // label texture
    std::vector<SDL_Texture*> labelTextures;
    SDL_Texture* getLabelTexture(std::string label);

    // label rects
    std::vector<SDL_Rect> labelRects;
    SDL_Rect getLabelRect(std::string);
    void updateLabelRect(int x, int y);

    // font
    std::string fontPath = "./assets/OpenSans-Regular.ttf";
    TTF_Font* font;
    SDL_Color fontColor = { 255, 255, 255, 255 };
    int fontSize = 32;

    void loadFont();

    // cursor
    std::string cursorImagePath = "./assets/arrow-right.png";
    SDL_Texture* cursorImageTexture;
    SDL_Rect cursorImageRect;
    void loadCursorImage();

    // background
    SDL_Rect backgroundRect;
    SDL_Color backgroundColor = { 100, 100, 100, 255 };
    int backgroundPadding = 40;
    void updateBackgroundRect();
};

#endif // MENUSDLRENDERER_H
