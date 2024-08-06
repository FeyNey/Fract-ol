/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 00:21:29 by acoste            #+#    #+#             */
/*   Updated: 2024/08/07 00:39:17 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

/*
f(z) = z * z * z - 1;

Z0 = 0 - 1);

(x + yi)^3 = (x + yi) * (x + yi) * (x + yi)
=
//////%
*/

void	initialised_newton(t_complex *c, t_scale *s)
{
	s->old_min = 0;
	s->old_max = WIDTH;
	c->x = -1;
	c->y = -1;
}

void	newton_render(int x, int y, t_fractol *f)
{
	t_complex	z;
	t_complex	c;
	t_scale		s;
	int			i;
	int			color;

	initialised_newton(&c, &s);
	z.x = (scale(x, -2, 2, &s) * f->zoom) + f->shift_x;
	s.old_max = HEIGHT;
	z.y = (scale(y, 2, -2, &s) * f->zoom) + f->shift_y;
	i = 0;
	s.old_max = f->iteration_definition;
	while (i < f->iteration_definition)
	{
		z = sum_complexe((square_complex(square_complex(z))), c);
		if ((z.x * z.x * z.x) + (z.y * z.y * z.y) > f->escape_value)
		{
			color = scale(i, 0x000000, 0xFFFFFF, &s);
			my_pixel_put(x, y, &f->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &f->img, 0xFF0000);
}
