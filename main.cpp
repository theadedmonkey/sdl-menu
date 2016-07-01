#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "include/Style.h"
#include "include/MenuItem.h"


const int SCREEN_WIDTH = 800;
const int SCREEN_WIDTH_HALF = SCREEN_WIDTH / 2;

const int SCREEN_HEIGHT = 600;
const int SCREEN_HEIGHT_HALF = SCREEN_HEIGHT / 2;

const int FPS = 120;
const int DELAY_TIME = 1000.0f / FPS;

SDL_Window* createWindow()
{
  /*
   * title - the window caption/title that appears on the top of the window
   * posX  - x position of the window
   * posY  - y position of the window
   * sizeW - width of the window
   * sizeH - height of the window
   * flags - specifies window state or properties
   *         see: https://wiki.libsdl.org/SDL_WindowFlags
   */
  return SDL_CreateWindow(
    "SDL Tutorial",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    SCREEN_WIDTH, SCREEN_HEIGHT,
    SDL_WINDOW_SHOWN
  );
};

SDL_Renderer* createRenderer(SDL_Window* &window)
{
  /*
   * window - the SDL_Window this renderer will be attached to. In our case, this
   *          is the SDL_Window we just created.
   * index  - specifies which rendering driver to use. It sounds complicated, but
   *          we can just specify -1. This means we’ll use the first driver we can find.
   * flags  - species how the rendering should be done. For now, we’ll just use
   *          SDL_RENDERER_ACCELERATED which lets us use the graphics card to render quickly.
   *          see: https://wiki.libsdl.org/SDL_RendererFlags?highlight=%28\bCategoryEnum\b%29|%28SDLEnumTemplate%29
   */
  return SDL_CreateRenderer(
    window,
    -1,
    SDL_RENDERER_ACCELERATED
  );
};

bool init()
{
  bool initialized = true;
  if (SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
  {
    std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
    initialized = false;
  }
  return initialized;
}

void close(SDL_Window* &window, SDL_Renderer* &renderer)
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  //Quit SDL subsystems
  SDL_Quit();
}

int main(int argc, char* args[])
{

  if(!init())
  {
    std::cout << "Failed to initialize!" << std::endl;
    return 0;
  }

  if (TTF_Init() == -1)
  {
    std::cout << "Init TTF  failt: " << SDL_GetError() << std::endl;
    return -1;
  }

  // The window we'll be rendering to
  SDL_Window* window = createWindow();

  // The window renderer
  SDL_Renderer* renderer = createRenderer(window);

  // Main loop flag
  bool quit = false;

  //Event handler
  SDL_Event e;

  Uint32 frameStart, frameTime;

  Style style;
  style.x = 100;
  style.y = 100;
  style.padding = 80;
  style.fontName = "Roboto-Black.ttf";
  style.fontColor = { 200, 100, 100, 255 };
  style.fontSize = 44;
  style.backgroundColor = { 100, 200, 200, 255 };

  Style style_hover;
  style_hover.x = 100;
  style_hover.y = 100;
  style_hover.padding = 80;
  style_hover.fontName = "Roboto-Black.ttf";
  style_hover.fontColor = { 10, 100, 176, 255 };
  style_hover.fontSize = 44;
  style_hover.backgroundColor = { 45, 46, 123, 255 };

  MenuItem* menuItem = new MenuItem(renderer, "Option", &style, &style_hover);

  // game loop
  while(!quit)
  {
    frameStart = SDL_GetTicks();

    while(SDL_PollEvent(&e) != 0)
    {
      // User requests quit
      if(e.type == SDL_QUIT)
      {
        quit = true;
      }

      menuItem->processEvent(&e);
    }


    SDL_SetRenderDrawColor(renderer, 000, 000, 000, 255);
    SDL_RenderClear(renderer);

    menuItem->render();

    SDL_RenderPresent(renderer);

    frameTime = SDL_GetTicks() - frameStart;
    if (frameTime < DELAY_TIME)
    {
      SDL_Delay((int) (DELAY_TIME - frameTime));
    }
  }

  close(window, renderer);
  return 0;
}
