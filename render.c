#include "fractol.h"
#include "minilibx-linux/mlx.h"

// t_complex quickmath(t_complex z, double cx, double cy)
// {
//     double xtemp;

//     // z.x = 0;
//     // z.y = 0;
//     xtemp = (z.x * z.x) - (z.y * z.y);
//     z.y = 2 * z.x * z.y;
//     z.x = xtemp;
//     z.x += cx;
//     z.y += cy;
//     return (z);
// }

 void	my_pixel_put(int x, int y, t_image *img, int color)
{
	int	offset;

	offset = (y * img->ll) + (x * (img->bpp / 8));
	*(unsigned int *)(img->addr + offset) = color;
}

// double converter(double num, double dimension, double min, double max) // resize from 0 to 800 -> -2 to 2
// {
//     return ((max - min) * (num / dimension) - 2);
// }

void put_pixel(int x, int y, t_fractal *fractal)
{
    t_complex z;
    t_complex c;
    int i;
    int color;

    i = 0;
    z.x = (converter(x, WIDTH, -2, 2) * fractal->zoom) + fractal->shift_x;
    z.y = (converter(y, HEIGHT, -2, 2) * fractal->zoom) + fractal->shift_y;
    c.x = (converter(x, WIDTH, -2, 2) * fractal->zoom) + fractal->shift_x;   // maybe put minmax in converter
    c.y = (converter(y, HEIGHT, -2, 2) * fractal->zoom) + fractal->shift_y;  // maybe put minmax in converter
    if (!ft_strncmp(fractal->name, "julia", 5))
    {
        c.x = fractal->julia_x;
        c.y = fractal->julia_y;
    }
    while(i < (ITERATIONS + fractal->i_var))
    {
        z = quickmath(z, c.x, c.y);
        if((z.x * z.x) + (z.y * z.y) > 4.0)
        {
            color = converter(i, (ITERATIONS), (BLACK), WHITE) + fractal->i_var;
            my_pixel_put(x, y, &fractal->image, color);
            return ;
        }
        i++;
    }
    my_pixel_put(x, y, &fractal->image, AQUA_DREAM);
}

void render(t_fractal *fractal)
{
    int x;
    int y;

    y = -1;
    while(y++ < WIDTH)
    {
        x = -1;
        while(x++ < HEIGHT)
        {
            put_pixel(x, y, fractal);
        }
    }
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->image.img, 0, 0);
}