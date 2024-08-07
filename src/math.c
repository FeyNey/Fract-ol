/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 20:40:39 by acoste            #+#    #+#             */
/*   Updated: 2024/08/07 02:27:04 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	ft_atoi_to_double(char *argv)
{
	double	sign;
	long	integer_part;
	double	fractional_part;
	double	pow;

	pow = 1;
	sign = 1;
	integer_part = 0;
	fractional_part = 0;
	if (*argv == '-' || *argv == '+')
	{
		if (*argv == '-')
			sign = sign * (-1);
		argv++;
	}
	while (*argv >= '0' && *argv <= '9')
		integer_part = (integer_part * 10) + (*argv++ - '0');
	if (*argv == '.')
		argv++;
	while (*argv)
	{
		pow /= 10;
		fractional_part = fractional_part + (*argv++ - '0') * pow;
	}
	return ((integer_part + fractional_part) * sign);
}

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

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

// real = (x * x - y * y)
// imaginary = 2 * x * y