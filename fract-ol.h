/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:00:14 by acoste            #+#    #+#             */
/*   Updated: 2024/08/03 20:45:08 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1000
# define HEIGHT 1000
# define MAX_ITER 100

# include <unistd.h> // write
# include <stdio.h> //printf pas autorise
# include <stdlib.h> // malloc / free
# include <math.h>
# include "minilibx-linux/mlx.h"

#define BLACK   0x000000
#define WHITE   0xFFFFFF
#define RED     0xFF0000
#define GREEN   0x00FF00
#define BLUE    0x0000FF
#define YELLOW  0xFFFF00

#define PURPLE 0x660066
#define LIME   0xCCFF00

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
}	t_fractol;

int		ft_strcmp(char *s1, char *s2);
void	chekargs(int argc, char **argv);
void	fractol_render(t_fractol *f);
void	fractol_init(t_fractol *f);
void	ft_malloc_error();
void	handle_pixel(int x, int y, t_fractol *f);
void	my_pixel_put(int x, int y, t_img *img, int color);
t_complex	square_complex(t_complex z);
t_complex	sum_complexe(t_complex z1, t_complex z2);
double		scale(double unscaled_num, double new_min, double new_max, t_scale *t);
t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z1, t_complex z2);

#endif