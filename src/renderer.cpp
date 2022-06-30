#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_size)
    : screen_size(screen_size)
{
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_size,
                                screen_size, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window)
  {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer)
  {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer()
{
  SDL_DestroyRenderer(sdl_renderer);
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(int buffer[])
{
  SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 0);
  SDL_RenderClear(sdl_renderer);

  for (int i = 0; i < screen_size; ++i)
    for (int j = 0; j < screen_size; ++j)
    {
      int index = i * screen_size + j;
      int color = buffer[index];
      SDL_SetRenderDrawColor(sdl_renderer, color, 0, 0, 255);
      SDL_RenderDrawPoint(sdl_renderer, j, i);
    }

  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps)
{
  std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
