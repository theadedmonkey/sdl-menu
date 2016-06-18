#include "MenuSDLRenderer.h"

#include <string>
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <Menu.h>

MenuSDLRenderer::MenuSDLRenderer(Menu* menu, SDL_Renderer* renderer)
{
  this->menu = menu;
  this->renderer = renderer;
  this->loadFont();
  this->loadCursorImage();

  // create cursor image rect
  int cursorImageW, cursorImageH;
  SDL_QueryTexture(this->cursorImageTexture, nullptr, nullptr, &cursorImageW, &cursorImageH);
  this->cursorImageRect = { 0, 0, cursorImageW, cursorImageH };

  // create label textures and label rects
  std::string l;
  for (int i = 0; i < this->menu->getItemCount(); i++)
  {
    l = this->menu->getItem(i)->getLabel();
    this->labelTextures.push_back(this->getLabelTexture(l));
    this->labelRects.push_back(this->getLabelRect(l));
  }
}

MenuSDLRenderer::~MenuSDLRenderer()
{
    //dtor
}

void MenuSDLRenderer::render()
{
  for (int i = 0; i < this->menu->getItemCount(); i++)
  {
    SDL_RenderCopy(this->renderer, this->labelTextures[i], nullptr, &this->labelRects[i]);

    if (this->menu->getSelectedItemIndex() == i)
    {
      // puts the cursor image at the right of the label
      this->cursorImageRect.x = this->labelRects[i].x + this->labelRects[i].w;
      this->cursorImageRect.y = this->labelRects[i].y + this->labelRects[i].h / 2 - this->cursorImageRect.h / 2;
      SDL_RenderCopy(this->renderer, this->cursorImageTexture, nullptr, &this->cursorImageRect);
    }
  }
}

MenuSDLRenderer::labelSurfaceSize MenuSDLRenderer::getLabelSurfaceSize(std::string label)
{
  const char *l = label.c_str();
  int w, h;
  TTF_SizeText(this->font, l, &w, &h);
  return { label, w, h };
}

SDL_Texture* MenuSDLRenderer::getLabelTexture(std::string label)
{
  SDL_Surface* labelSurface = TTF_RenderText_Solid(this->font, label.c_str(), this->fontColor);
  if (labelSurface == NULL)
  {
    std::cout << "Unable to render text surface! SDL_ttf Error: " << TTF_GetError() << std::endl;
    return nullptr;
  }

  SDL_Texture* labelTexture = SDL_CreateTextureFromSurface(this->renderer, labelSurface);
  if (labelTexture == NULL)
  {
    std::cout << "Unable to create texture from rendered text! SDL Error: " << SDL_GetError() << std::endl;
    return nullptr;
  }
  SDL_FreeSurface(labelSurface);
  return labelTexture;
}

SDL_Rect MenuSDLRenderer::getLabelRect(std::string label)
{
  MenuSDLRenderer::labelSurfaceSize labelSurfaceSize = this->getLabelSurfaceSize(label);
  int x = 0;
  int y = this->menu->getIndex(label) * labelSurfaceSize.h;
  int w = labelSurfaceSize.w;
  int h = labelSurfaceSize.h;
  return { x, y, w, h };
}

void MenuSDLRenderer::loadFont()
{
  this->font = TTF_OpenFont(this->fontPath.c_str(), this->fontSize);
  if (this->font == nullptr) {
    std::cout << "Failed to load font " << this->fontPath << " error: " << SDL_GetError() << std::endl;
  }
}

void MenuSDLRenderer::loadCursorImage()
{
  this->cursorImageTexture = IMG_LoadTexture(this->renderer, this->cursorImagePath.c_str());
  if (cursorImageTexture == nullptr) {
    std::cout << "Failed to load texture " << this->cursorImagePath << " error : " << SDL_GetError() << std::endl;
  }
}
