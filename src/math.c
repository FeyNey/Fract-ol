/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 20:40:39 by acoste            #+#    #+#             */
/*   Updated: 2024/08/07 00:39:14 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	scale(double unscaled_num, double new_min, double new_max, t_scale *t)
{
	t->unscaled_num = unscaled_num;
	t->new_max = new_max;
	t->new_min = new_min;
	return ((new_max - new_min) * (unscaled_num - t->old_min)
		/ (t->old_max - t->old_min) + new_min);
}

/* [0 - 799] -> [-2 - 2]*/

t_complex	sum_complexe(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	sum_semi_complexe(t_complex z1, int z2)
{
	t_complex	result;

	result.x = z1.x + z2;
	result.y = z1.y + z2;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

// real = (x * x - y * y)
// imaginary = 2 * x * y