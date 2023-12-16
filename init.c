/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscholz <dscholz@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:01:04 by dscholz           #+#    #+#             */
/*   Updated: 2023/12/14 17:35:17 by dscholz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <X11/X.h>

int	clean_exit(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->image.img);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	keyboard(int key, t_fractal *fractal)
{
	if (key == XK_Escape)
		clean_exit(fractal);
	if (key == XK_Left)
		fractal->shift_x -= (0.5 * fractal->zoom);	
	else if (key == XK_Right)
		fractal->shift_x += (0.5 * fractal->zoom);	
	else if (key == XK_Up)
		fractal->shift_y -= (0.5 * fractal->zoom);	
	else if (key == XK_Down)
		fractal->shift_y += (0.5 * fractal->zoom);	
	else if (key == XK_plus)
		fractal->i_var += 1;
	else if (key == XK_minus)	
		fractal->i_var -= 1;
	render(fractal);
	return (0);
}

int mouse(int key, int x, int y, t_fractal *fractal)
{
	if (key == Button5)
	{
		fractal->zoom *= 1.05;
	}
	else if (key == Button4)
	{
		fractal->zoom *= 0.95;
	}
	render(fractal);
	return (0);
}

void	hooks(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, keyboard, fractal);
	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, mouse, fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask,
		clean_exit, fractal);
}

void	init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		freem();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
			WIDTH, HEIGHT, fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		freem();
	}
	fractal->image.img = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (fractal->image.img == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		freem();
	}
	fractal->image.addr = mlx_get_data_addr(fractal->image.img,
			&fractal->image.bpp, &fractal->image.ll, &fractal->image.endian);
	hooks(fractal);
}
