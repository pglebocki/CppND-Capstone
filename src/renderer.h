#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "color.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_size);
  ~Renderer();

  void Render(Color buffer[]);
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_size;
};

#endif