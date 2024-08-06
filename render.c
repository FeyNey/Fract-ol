/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 00:27:02 by acoste            #+#    #+#             */
/*   Updated: 2024/08/06 19:33:50 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//toutes les fonctions de rendering
//deuxieme partie de mon code

#include "fract-ol.h"

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_lenght) + (x * (img->bpp / 8));
	*(unsigned int *)(img->data + offset) = color;
}

void	initialised_mandel(t_complex *z, t_scale *s)
{
	z->x = 0.0;
	z->y = 0.0;
	s->old_min = 0;
	s->old_max = WIDTH;
}

void	mandelbrot_render(int x, int y, t_fractol *f)
{
	t_complex	z;
	t_complex	c;
	t_scale		s;
	int			i;
	double		color;

	initialised_mandel(&z, &s);
	c.x = (scale(x, -2, +2, &s) * f->zoom) + f->shift_x;
	s.old_max = HEIGHT;
	c.y = (scale(y, +2, -2, &s) * f->zoom) + f->shift_y;
	i = 0;
	s.old_max = f->iteration_definition;
	while (i < f->iteration_definition)//nbr iteration //verif
	{
		z = sum_complexe(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > f->escape_value)
		{
			color = scale(i, BLACK, WHITE, &s);
			my_pixel_put(x ,y, &f->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &f->img, PURPLE);
}
		// z carre + c;

void	initialised_julia(t_complex *c, t_scale *s, t_fractol *f)
{
	s->old_min = 0;
	s->old_max = WIDTH;
	c->x = f->arg_x;
	c->y = f->arg_y;
}

void julia_render(int x, int y, t_fractol *f)
{
	t_complex	z;
	t_complex	c;
	t_scale		s;
	int			i;
	int			color;

	initialised_julia(&c, &s, f);
	z.x = (scale(x, -2, 2, &s) * f->zoom) + f->shift_x;
	s.old_max = HEIGHT;
	z.y = (scale(y, 2, -2, &s) * f->zoom) + f->shift_y;
	i = 0;
	s.old_max = f->iteration_definition;
	while (i < f->iteration_definition)//nbr iteration //verif
	{
		z = sum_complexe(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > f->escape_value)
		{
			color = scale(i, BLACK, WHITE, &s);
			my_pixel_put(x ,y, &f->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &f->img, PURPLE);
}

void	initialised_newton(t_complex *z, t_scale *s)
{
	s->old_min = 0;
	s->old_max = WIDTH;
	z->x = 0;
	z->y = 0;
}

void	newton_render(int x, int y, t_fractol *f)
{
	t_complex	z;
	t_complex	c;
	t_scale		s;
	int			i;
	int			color;

	initialised_newton(&z, &s);
	c.x = (scale(x, -2, 2, &s) * f->zoom) + f->shift_x;
	z.x = (scale(x, -2, 2, &s) * f->zoom) + f->shift_x;
	s.old_max = HEIGHT;
	c.y = (scale(y, 2, -2, &s) * f->zoom) + f->shift_y;
	z.y = (scale(y, 2, -2, &s) * f->zoom) + f->shift_y;
	i = 0;
	s.old_max = f->iteration_definition;
	while (i < f->iteration_definition)
	{
		z = square_complex(z);
		z = sum_semi_complexe(square_complex(z), (-1));
		if ((z.x * z.x) + (z.y * z.y) > f->escape_value)
		{
			color = scale(i, BLACK, WHITE, &s);
			my_pixel_put(x ,y, &f->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &f->img, PURPLE);
}

void	handle_pixel(int x, int y, t_fractol *f, char **argv)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0
	|| ft_strcmp(argv[1], "Mandelbrot") == 0
	|| ft_strcmp(f->name, "mandelbrot") == 0
	|| ft_strcmp(f->name, "Mandelbrot") == 0)
	{
		mandelbrot_render(x, y, f);
	}

	if (ft_strcmp(argv[1], "julia") == 0
		|| ft_strcmp(argv[1], "Julia") == 0
		|| ft_strcmp(f->name, "julia") == 0
		|| ft_strcmp(f->name, "Julia") == 0)
	{
		julia_render(x, y, f);
	}
	if ((ft_strcmp(f->name, "Newton") == 0)
		|| (ft_strcmp(f->name, "newton") == 0))
	{
		newton_render(x, y, f);
	}
}

void	fractol_render(t_fractol *f, char **argv)
{
	int x;
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, f, argv);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->ptr, f->win, f->img.img_ptr, 0, 0);
}