#include "controller.h"
#include <iostream>
#include "SDL.h"

Controller::Controller(void (*onMouseClickEvent)(int, int))
    : onMouseClickEvent(onMouseClickEvent),
      mousePressed(false)
{
}

void Controller::HandleInput()
{
  SDL_Event event;
  while (true)
  {
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
      return;

    case SDL_MOUSEBUTTONDOWN:
      if (!mousePressed)
      {
        mousePressed = true;
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        onMouseClickEvent(mouseX, mouseY);
      }
      break;
    case SDL_MOUSEBUTTONUP:
      mousePressed = false;
    }
  }
}