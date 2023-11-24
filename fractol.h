#ifndef FRACTOL_H
#   define FRACTOL_H

#   include <stdio.h>
#   include <stdlib.h>
#   include <unistd.h>
#   include <math.h>
#   include "minilibx-linux/mlx.h"

#define WIDTH 800
#define HEIGHT 800



typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;


typedef struct s_fractal
{
    char *name;
    void *mlx_connection;
    void *mlx_window;
    t_image image;
}				t_fractal;

typedef struct s_complex
{
    double x; //real
    double y; //i
}   t_complex;


int	ft_strncmp(const char *str1, const char *str2, size_t n);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
static void freem(void);
void init(t_fractal *fractal);

#endif