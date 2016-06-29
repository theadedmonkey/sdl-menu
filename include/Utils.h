#ifndef SDLUTILS_H
#define SDLUTILS_H

#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

TTF_Font* createFont(std::string path, int size);

SDL_Texture* createTextTexture(
  SDL_Renderer* renderer,
  std::string label,
  TTF_Font* f,
  SDL_Color color
);

SDL_Rect createRectFromTexture(SDL_Texture* texture);

#endif // SDLUTILS_H
