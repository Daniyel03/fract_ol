#ifndef FRACTOL_H
#   define FRACTOL_H

#   include <stdio.h>
#   include <stdlib.h>
#   include <unistd.h>
#   include <math.h>
#   include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

#define ERROR_MESSAGE "./fractol mandelbrot || ./fractol julia \"x value\" \"y value\"\n"
#define WIDTH 800
#define HEIGHT 800
#define ITERATIONS 42

#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)
#define RED         0xFF0000  // RGB(255, 0, 0)
#define GREEN       0x00FF00  // RGB(0, 255, 0)
#define BLUE        0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
#define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
#define LIME_SHOCK      0xCCFF00  // A blinding lime
#define NEON_ORANGE     0xFF6600  // A blazing neon orange
#define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
#define AQUA_DREAM      0x33CCCC  // A bright turquoise
#define HOT_PINK        0xFF66B2  // As the name suggests!
#define ELECTRIC_BLUE   0x0066FF  // A radiant blue
#define LAVA_RED        0xFF3300  // A bright, molten red


typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}				t_image;

/*bpp = bits per pixel, ll line length*/

typedef struct s_fractal
{
    char *name;
    void *mlx_connection;
    void *mlx_window;
    t_image image;
    double esc_value;   // cant i preddefine (put 2 in f)
    int iterations;
    double shift_x;
    double shift_y;
    // double min; // old -2
    // double max; // old 2
    double zoom;
    int i_var;
    double julia_x;
    double julia_y;
}				t_fractal;

typedef struct s_complex
{
    double x; //real
    double y; //i
}   t_complex;


int	ft_strncmp(const char *str1, const char *str2, size_t n);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
void freem(void);
void init(t_fractal *fractal);
t_complex quickmath(t_complex z, double cx, double cy);
void	my_pixel_put(int x, int y, t_image *img, int color);
double converter(double num, double dimension, double min, double max);
void put_pixel(int x, int y, t_fractal *fractal);
void render(t_fractal *fractal);
int	clean_exit(t_fractal *fractal);
int keyboard(int key, t_fractal *fractal);
void hooks(t_fractal *fractal);
int mouse(int key, int x, int y, t_fractal *fractal);
double atodouble(char *str);

#endif