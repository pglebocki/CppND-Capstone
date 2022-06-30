#include "fractal.h"

Fractal::Fractal(int screen_size) : screen_size(screen_size)
{
}

void Fractal::generate(int buffer[], double x_start, double x_end, double y_start, double y_end)
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
            buffer[index] = value;
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