/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:59:50 by acoste            #+#    #+#             */
/*   Updated: 2024/08/07 00:41:25 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

/*
f(z) = z * z + c;

Z0 = 0 + (point (5 , 2i));

(x + yi)^2 = (x + yi) * (x + yi)
=
x^2 - y^2 + 2xyi;
*/

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
	while (i < f->iteration_definition)
	{
		z = sum_complexe(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > f->escape_value)
		{
			color = scale(i, 0x000000, 0xFFFFFF, &s);
			my_pixel_put(x, y, &f->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &f->img, 0x660066);
}
