#include "fractol.h"

static void freem(void)
{
    perror("no");
    exit(EXIT_FAILURE);
}

void init(t_fractal *fractal)
{
    fractal->mlx_connection = mlx_init();
    if (fractal->mlx_connection == NULL)
        freem();
    fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT, fractal->name);
    if (fractal->mlx_window == NULL)
    {
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        freem();
    }
    fractal->image.img = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
    if (fractal->image.addr == NULL)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        freem();
    }
    fractal->image.addr = mlx_get_data_addr(fractal->image.img, &fractal->image.bits_per_pixel, &fractal->image.line_length, &fractal->image.endian);

}