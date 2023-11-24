#include "fractol.h"


int main(int argc, char **argv)
{
    t_fractal fractal;
    if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)
    || argc == 4 && !ft_strncmp(argv[1], "julia", 5))
    {
        fractal.name = argv[1];
        init(&fractal);
    }
    else
    {
        ft_putstr_fd("nooo", STDERR_FILENO);
        exit(EXIT_FAILURE);
    }


    // t_complex z;
    // t_complex c;
    // double xtemp;

    // z.x = 0;
    // z.y = 0;
    // c.x = 0.25;
    // c.y = 0.4;
    // for (int i = 0; i < 20; i++)
    // {
    //     xtemp = (z.x * z.x) - (z.y * z.y);
    //     z.y = 2 * z.x * z.y;
    //     z.x = xtemp;
    //     z.x += c.x;
    //     z.y += c.y;
    //     printf("nr. %d \t x. %f \t y. %f\n", i, z.x, z.y);
    // }
    return 0;
}