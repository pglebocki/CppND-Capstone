#include <iostream>
#include "controller.h"
#include "renderer.h"
#include "fractal.h"
#include "color.h"

#define WINDOW_SIZE 600

double x_start = -2.0;
double x_end = 1.0;
double y_start = -1.5;
double y_end = 1.5;

Color screen_buffer[WINDOW_SIZE * WINDOW_SIZE];
Fractal fractal(WINDOW_SIZE);
Renderer renderer(WINDOW_SIZE);

void onMouseClicked(int x, int y)
{
  double width = abs(x_end - x_start);
  double height = abs(y_end - y_start);
  double new_width = width / 2;
  double new_height = height / 2;

  double x_click_ratio = double(x) / WINDOW_SIZE;
  double y_click_ratio = 1.0 - double(y) / WINDOW_SIZE;

  double new_center_x = x_start + width * x_click_ratio;
  double new_center_y = y_start + height * y_click_ratio;

  x_start = new_center_x - new_width / 2;
  x_end = new_center_x + new_width / 2;
  y_start = new_center_y - new_height / 2;
  y_end = new_center_y + new_height / 2;

  fractal.generate(screen_buffer, x_start, x_end, y_start, y_end);
  renderer.Render(screen_buffer);
}

int main()
{
  fractal.generate(screen_buffer, x_start, x_end, y_start, y_end);
  renderer.Render(screen_buffer);

  Controller controller(&onMouseClicked);
  controller.HandleInput();

  return EXIT_SUCCESS;
}