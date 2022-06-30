#include <iostream>
#include "controller.h"
#include "renderer.h"
#include "fractal.h"

#define WINDOW_SIZE 600

void onMouseClicked(int x, int y) {
  std::cout<<x<<":"<<y<<" ";
  // TODO recalculate
}

int main()
{
  int screen_buffer[WINDOW_SIZE * WINDOW_SIZE];
  Fractal fractal(WINDOW_SIZE);
  fractal.generate(screen_buffer, -2.0, 1.0, -1.5, 1.5);

  SDL_Event event;
  Renderer renderer(WINDOW_SIZE);
  renderer.Render(screen_buffer);

  Controller controller(&onMouseClicked);
  controller.HandleInput();

  return EXIT_SUCCESS;
}