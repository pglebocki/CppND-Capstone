#include <iostream>
#include "controller.h"
#include "renderer.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600

int mandelbrot(double real, double imag)
{
  int limit = 100;
  double zReal = real;
  double zImag = imag;

  for (int i = 0; i < limit; ++i)
  {
    double r2 = zReal * zReal;
    double i2 = zImag * zImag;

    if (r2 + i2 > 4.0)
      return i;

    zImag = 2.0 * zReal * zImag + imag;
    zReal = r2 - i2 + real;
  }
  return limit;
}

void initFractal(int buffer[])
{
  int width = WINDOW_WIDTH;
  int heigth = WINDOW_HEIGHT;

  double x_start = -2.0;
  double x_fin = 1.0;
  double y_start = -1.0;
  double y_fin = 1.0;

  double dx = (x_fin - x_start) / (width - 1);
  double dy = (y_fin - y_start) / (heigth - 1);

  for (int i = 0; i < heigth; i++)
  {
    for (int j = 0; j < width; j++)
    {
      double x = x_start + j * dx; // current real value
      double y = y_fin - i * dy;   // current imaginary value

      int value = mandelbrot(x, y);
      int index = i * WINDOW_WIDTH + j;
      buffer[index] = value;
    }
  }
}

int main()
{
  int screen_buffer[WINDOW_WIDTH * WINDOW_HEIGHT];
  initFractal(screen_buffer);

  SDL_Event event;
  Renderer renderer(WINDOW_WIDTH, WINDOW_HEIGHT);
  renderer.Render(screen_buffer);

  while (1)
  {
    if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
      break;
  }

  return EXIT_SUCCESS;
}