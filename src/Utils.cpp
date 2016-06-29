#include "../include/Utils.h"

TTF_Font* createFont(std::string path, int size)
{
  TTF_Font* f = TTF_OpenFont(path.c_str(), size);
  if (f == nullptr) {
    std::cout << "Failed to load font " << path << " error: " << SDL_GetError() << std::endl;
  }
  return f;
}

SDL_Texture* createTextTexture(
  SDL_Renderer* renderer,
  std::string label,
  TTF_Font* f,
  SDL_Color color
)
{
  SDL_Surface* surface = TTF_RenderText_Solid(f, label.c_str(), color);
  if (surface == nullptr)
  {
    std::cout << "Unable to render text surface! SDL_ttf Error: " << TTF_GetError() << std::endl;
    return nullptr;
  }

  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
  if (texture == nullptr)
  {
    std::cout << "Unable to create texture from rendered text! SDL Error: " << SDL_GetError() << std::endl;
  }
  SDL_FreeSurface(surface);
  return texture;
}

SDL_Rect createRectFromTexture(SDL_Texture* texture)
{
  SDL_Rect rect = { 0, 0, 0, 0 };
  int rectW, rectH;
  SDL_QueryTexture(texture, nullptr, nullptr, &rectW, &rectH);

  rect.w = rectW;
  rect.h = rectH;

  return rect;
}
