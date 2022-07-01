#ifndef FRATAL_H
#define FRATAL_H

#include "color.h"

class Fractal
{
public:
    Fractal(int screen_size);
    void generate(Color buffer[], double x_start, double x_end, double y_start, double y_end);

private:
    int screen_size;

    int mandelbrot(double real, double imag);
    Color mapColor(int value);
};

#endif