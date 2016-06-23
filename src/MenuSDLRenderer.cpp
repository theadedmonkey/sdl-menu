#include "MenuSDLRenderer.h"

#include <string>
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <Menu.h>

MenuSDLRenderer::MenuSDLRenderer(Menu* menu, SDL_Renderer* renderer, int x, int y)
{
  // sdl renderer
  this->renderer = renderer;
  this-> x = x;
  this-> y = y;
  this->loadFont();
  this->loadCursorImage();

  // create cursor image rect
  int cursorImageW, cursorImageH;
  SDL_QueryTexture(this->cursorImageTexture, nullptr, nullptr, &cursorImageW, &cursorImageH);
  this->cursorImageRect = { 0, 0, cursorImageW, cursorImageH };

  this->setMenu(menu);
}

MenuSDLRenderer::~MenuSDLRenderer()
{
    //dtor
}

void MenuSDLRenderer::createLabelTexturesAndRects()
{
  this->labelTextures.clear();
  this->labelRects.clear();

  std::string l;
  for (int i = 0; i < this->menu->getItemCount(); i++)
  {
    l = this->menu->getItem(i)->getLabel();
    this->labelTextures.push_back(this->getLabelTexture(l));
    this->labelRects.push_back(this->getLabelRect(l));
  }
}

void MenuSDLRenderer::setMenu(Menu* menu)
{
  this->menu = menu;
  this->menu->setRenderer(this);

  this->createLabelTexturesAndRects();
  this->updateBackgroundRect();
}

int MenuSDLRenderer::getW()
{
  /*
   * menu width is equal to the width of the menu item
   * with highest width plus the width of the cursor rect.
   */
  int maximun = 0;
  int labelRectW;
  for (int i = 0; i < this->menu->getItemCount(); i++)
  {
    labelRectW = this->labelRects[i].w;
    if (labelRectW > maximun)
    {
      maximun = labelRectW;
    }
  }
  return maximun + this->cursorImageRect.w;
}

int MenuSDLRenderer::getH()
{
  /*
   * menu height is equal to the sum of the heights
   * of all the menu item heights.
   */
  int sum = 0;
  for (int i = 0; i < this->menu->getItemCount(); i++)
  {
    sum += this->labelRects[i].h;
  }
  return sum;
}

void MenuSDLRenderer::setX(int x)
{
  this->x = x;
  MenuSDLRenderer::updateLabelRect(x, 0);
  MenuSDLRenderer::updateBackgroundRect();
}

void MenuSDLRenderer::setY(int y)
{
  this->y = y;
  MenuSDLRenderer::updateLabelRect(0, y);
  MenuSDLRenderer::updateBackgroundRect();
}

void MenuSDLRenderer::updateLabelRect(int x, int y)
{
  for (unsigned int i = 0; i < this->labelRects.size(); i++)
  {
    if (x)
    {
      this->labelRects[i].x += x;
    }
    if (y)
    {
      this->labelRects[i].y += y;
    }
  }
}

void MenuSDLRenderer::updateBackgroundRect()
{
  this->backgroundRect = {
    this->x - this->backgroundPadding,
    this->y - this->backgroundPadding,
    this->getW() + this->backgroundPadding * 2,
    this->getH() + this->backgroundPadding * 2
  };
}

void MenuSDLRenderer::render()
{
  // render background
  SDL_SetRenderDrawColor(this->renderer, 100, 100, 100, 100);
  SDL_RenderFillRect(this->renderer, &this->backgroundRect);
  // render menu items
  for (int i = 0; i < this->menu->getItemCount(); i++)
  {
    SDL_RenderCopy(this->renderer, this->labelTextures[i], nullptr, &this->labelRects[i]);

    if (this->menu->getSelectedItemIndex() == i)
    {
      // render cursor image, image appears at the right of the label
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
  int x = 0 + this->x;
  int y = this->menu->getIndex(label) * labelSurfaceSize.h + this->y;
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
