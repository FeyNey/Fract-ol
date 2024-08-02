/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 00:27:02 by acoste            #+#    #+#             */
/*   Updated: 2024/08/02 21:25:35 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//toutes les fonctions de rendering
//deuxieme partie de mon code

#include "fract-ol.h"

double	scale(double unscaled_num, double new_min, double new_max, t_scale *t)
{
	t->unscaled_num = unscaled_num;
	t->new_max = new_max;
	t->new_min = new_min;
	return ((new_max - new_min) * (unscaled_num - t->old_min)
			/ (t->old_max - t->old_min) + new_min);
}

/* [0 - 799] -> [-2 - 2]*/

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
}

t_complex	square_complex(int x)
{

}

void	handle_pixel(int x, int y, t_fractol *f)
{
	t_complex z;
	t_complex c;
	t_scale s;

// iterations
	z.x = 0.0;
	z.y = 0.0;

	s.old_min = WIDTH;
	c.x = scale(x, -2, +2, &s);
	s.old_min = HEIGHT;
	c.x = scale(y, +2, -2, &s);
	while ()//nbr iteration
	{
		// z carre + c
		z = sum_complexe((square_complex(z), c));
		if ()//is not in the fractal,
		{
			my_pixel_put();
			return ;
		}
		else
		{
			my_pixel_put();
			return ;
		}
	}
}

void	fractol_render(t_fractol *f)
{
	int x;
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, f);
		}
		y++;
	}
}