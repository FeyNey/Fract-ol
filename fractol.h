/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:00:14 by acoste            #+#    #+#             */
/*   Updated: 2024/08/07 03:25:32 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1000
# define HEIGHT 1000

# include <unistd.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include <stdio.h> //printf pas autorise

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

	// real x
	// imaginary y

typedef struct s_upscale
{
	double	unscaled_num;
	double	new_min;
	double	new_max;
	double	old_min;
	double	old_max;
	int		iteration_definition;
}			t_scale;

typedef struct s_img // values from mlx_get_data_adress
{
	void		*img_ptr;
	char		*data;
	int			bpp;
	int			line_lenght;
	int			endian;
}				t_img;

typedef struct s_fractol
{
	void	*ptr; // mlx_init
	void	*win; // mlx_window
	char	*name; // fractol name
	t_img	img; // mlx_get_data_adress
	double	escape_value;
	int		iteration_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	arg_x;
	double	arg_y;
	int		color_shift;
}	t_fractol;

//math.c
double		ft_atoi_to_double(char *argv);
double		scale(double unscaled_num, double new_min,
				double new_max, t_scale *t);
t_complex	sum_complexe(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

//hook.c
int			close_handler(t_fractol *f);
int			key_handle(int keysym, t_fractol *f);
int			mouse_handle(int button, int x, int y, t_fractol *f);
// int			mouse_track(int x, int y, t_fractol *f);

//init.c
void		events_init(t_fractol *f);
int			ft_strncmp(char *s1, char *s2, int size);
void		ft_malloc_error(void);
void		fractol_init(t_fractol *f);

//Julia.c
void		initialised_julia(t_complex *c, t_scale *s, t_fractol *f);
void		julia_render(int x, int y, t_fractol *t);

//Mandelbrot.c
void		initialised_mandel(t_complex *z, t_scale *s);
void		mandelbrot_render(int x, int y, t_fractol *f);

//Newton.c
void		initialised_newton(t_complex *z, t_scale *s);
void		newton_render(int x, int y, t_fractol *f);

//render.c
void		my_pixel_put(int x, int y, t_img *img, int color);
void		handle_pixel(int x, int y, t_fractol *f);
void		fractol_render(t_fractol *f);

//main.c
void		valid_arg(char *argv);
void		julia_args_check(char **argv, t_fractol *f);
void		ft_error(int i);
void		chekargs(int argc, char **argv, t_fractol *f);

#endif