#ifndef STYLE_H
#define STYLE_H

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

struct Style {
  int x = 0;
  int y = 0;
  int w = 0;
  int h = 0;

  SDL_Color backgroundColor = { 0, 0, 0, 255 };

  std::string fontName;
  SDL_Color fontColor = { 255, 255, 255, 255 };
  int fontSize;
};

#endif // STYLE_H
