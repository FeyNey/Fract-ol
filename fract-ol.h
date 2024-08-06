/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:00:14 by acoste            #+#    #+#             */
/*   Updated: 2024/08/06 19:21:31 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1000
# define HEIGHT 1000

# include <unistd.h> // write
# include <stdio.h> //printf pas autorise
# include <stdlib.h> // malloc / free
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

#define BLACK   0x000000
#define WHITE   0xFFFFFF
#define RED     0xFF0000
#define GREEN   0x00FF00
#define BLUE    0x0000FF
#define YELLOW  0xFFFF00

#define PURPLE 0x660066
#define LIME   0xCCFF00
#define SBLACK 0xFFFFFF
#define SRED   0xFF3A00

typedef struct	s_complex
{
	// real
	double	x;
	// imaginary
	double	y;

}	t_complex;

typedef struct	s_upscale
{
	double	unscaled_num;
	double	new_min;
	double	new_max;
	double	old_min;
	double	old_max;
	int		iteration_definition;
}			t_scale;

typedef struct	s_img // values from mlx_get_data_adress
{
	void	*img_ptr;
	char	*data;
	int		bpp;
	int		line_lenght;
	int		endian;
	t_complex	m; // maldelbrot values
}				t_img;

typedef struct s_fractol
{
	void	*ptr; // mlx_init
	void	*win; // mlx_window
	char	*name; // fractol name
	t_img	img; // mlx_get_data_adress
	t_scale	scale;
	double	escape_value;
	int		iteration_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	arg_x;
	double	arg_y;
}	t_fractol;

int			ft_strcmp(char *s1, char *s2);
void		chekargs(int argc, char **argv, t_fractol *f);
void		fractol_render(t_fractol *f, char **argv);
void		fractol_init(t_fractol *f);
void		ft_malloc_error();
void		handle_pixel(int x, int y, t_fractol *f, char **argv);
void		my_pixel_put(int x, int y, t_img *img, int color);
t_complex	square_complex(t_complex z);
t_complex	sum_complexe(t_complex z1, t_complex z2);
double		scale(double unscaled_num, double new_min, double new_max, t_scale *t);
t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z1, t_complex z2);
int			key_handle(int keysym, t_fractol *f);
int			close_handler(t_fractol *f);
int			mouse_handle(int button, int x, int y, t_fractol *f);
void		mandelbrot_render(int x, int y, t_fractol *f);
void		initialised_mandel(t_complex *z, t_scale *s);
void		julia_render(int x, int y, t_fractol *t);
int			mouse_track(int x, int y, t_fractol *f);
void		ft_error(int i);
double		ft_atoi_to_double(char *argv);
void		julia_args_check(char **argv, t_fractol *f);
t_complex	sum_semi_complexe(t_complex z1, int z2);
void		initialised_newton(t_complex *z, t_scale *s);

#endif