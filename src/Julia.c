/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 00:19:12 by acoste            #+#    #+#             */
/*   Updated: 2024/08/07 02:53:24 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

/*
f(z) = z * z + c;

Z0 = 0 + (point (x , yi));

(x + yi)^2 = (x + yi) * (x + yi)
=
x^2 - y^2 + 2xyi;

C = constante x;y seul zn s'itere
*/

void	initialised_julia(t_complex *c, t_scale *s, t_fractol *f)
{
	s->old_min = 0;
	s->old_max = WIDTH;
	c->x = f->arg_x;
	c->y = f->arg_y;
}

void	julia_render(int x, int y, t_fractol *f)
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
	while (i < f->iteration_definition)
	{
		z = sum_complexe(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > f->escape_value)
		{
			color = scale(i, (0x000000 * f->color_shift),
					(0xFFFFFF * f->color_shift), &s);
			my_pixel_put(x, y, &f->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &f->img, 0x660066);
}
