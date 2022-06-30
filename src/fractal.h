#ifndef FRATAL_H
#define FRATAL_H

class Fractal
{
public:
    Fractal(int screen_size);
    void generate(int buffer[], double x_start, double x_end, double y_start, double y_end);

private:
    int screen_size;

    int mandelbrot(double real, double imag);
};

#endif