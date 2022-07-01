#include "fractal.h"
#include <iostream>
#include <cmath>

Fractal::Fractal(int screen_size) : screen_size(screen_size)
{
}

void Fractal::generate(Color buffer[], double x_start, double x_end, double y_start, double y_end)
{
    double dx = (x_end - x_start) / (screen_size - 1);
    double dy = (y_end - y_start) / (screen_size - 1);

    for (int i = 0; i < screen_size; i++)
    {
        for (int j = 0; j < screen_size; j++)
        {
            double x = x_start + j * dx;
            double y = y_end - i * dy;

            int value = mandelbrot(x, y);
            int index = i * screen_size + j;
            buffer[index] = mapColor(value);
        }
    }
}

int Fractal::mandelbrot(double real, double imag)
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

Color Fractal::mapColor(int value)
{
    if (value > 90)
        return Color(255, 0, 200);
    if (value > 80)
        return Color(225, 25, 175);
    if (value > 70)
        return Color(200, 50, 150);
    if (value > 60)
        return Color(175, 75, 125);
    if (value > 50)
        return Color(150, 100, 100);
    if (value > 40)
        return Color(125, 125, 125);
    if (value > 30)
        return Color(100, 150, 175);
    if (value > 20)
        return Color(75, 175, 200);
    if (value > 10)
        return Color(50, 200, 225);
    if (value > 0)
        return Color(0, 225, 255);

    return Color(0, 0, 0);
}