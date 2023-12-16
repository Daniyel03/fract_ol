/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscholz <dscholz@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:43:55 by dscholz           #+#    #+#             */
/*   Updated: 2023/12/14 17:04:46 by dscholz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"

t_complex	quickmath(t_complex z, double cx, double cy)
{
	double	xtemp;

	xtemp = (z.x * z.x) - (z.y * z.y);
	z.y = 2 * z.x * z.y;
	z.x = xtemp;
	z.x += cx;
	z.y += cy;
	return (z);
}
    
double	converter(double num, double dimension, double min, double max)
{
	return ((max - min) * (num / dimension) - 2);
}

void	freem(void)
{
	perror("no");
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	fractal.esc_value = 4.0;
	fractal.shift_x = 0.0;
	fractal.shift_y = 0.0;
	fractal.i_var = 0;
	fractal.zoom = 1.0;
	fractal.name = argv[1];
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		if (!ft_strncmp(fractal.name, "julia", 5))
		{
			fractal.julia_x = atodouble(argv[2]);
			fractal.julia_y = atodouble(argv[3]);
		}
		init(&fractal);
		render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
		return (ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO),
			exit(EXIT_FAILURE), 0);
}
