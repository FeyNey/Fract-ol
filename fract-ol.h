/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:00:14 by acoste            #+#    #+#             */
/*   Updated: 2024/08/02 00:09:44 by acoste           ###   ########.fr       */
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

typedef struct	s_mandelbrot
{
	double	real;
	double	i;


}	t_mandelbrot;

typedef struct	s_img // values from mlx_get_data_adress
{
	void	*img_ptr;
	char	*data;
	int		bpp;
	int		line_lenght;
	int		endian;
	t_mandelbrot	m; // maldelbrot values
}				t_img;

typedef struct s_fractol
{
	void	*ptr; // mlx_init
	void	*win; // mlx_window
	char	*name; // fractol name
	t_img	img; // mlx_get_data_adress

}	t_fractol;



int		ft_strcmp(char *s1, char *s2);
void	chekargs(int argc, char **argv);


#endif