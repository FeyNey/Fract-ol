/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:59:50 by acoste            #+#    #+#             */
/*   Updated: 2024/08/02 20:47:05 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"
/*
f(z) = z * z + c;

Z0 = 0 + (point (5 , 2i));

(x + yi)^2 = (x + yi) * (x + yi)
=
x^2 - y^2 + 2xyi;
*/

int	Mandelbrot(void)
{
	int i;
	t_complex z;
	t_complex c;
	double tmp_z;

	i = 0;

	z.x = 0;
	z.y = 0;

	c.x = 0.10;
	c.y = 0.4;

	while(i < 42)
	{
		//general formula
		// z = z^2 + c
	tmp_z = (z.x * z.x) - (z.y * z.y);
	z.y = 2 * z.x * z.y;
	z.x = tmp_z;
	z.x += c.x;
	z.y += c.y;
		i++;

	printf("iteration n -> %d z %f imaginary %f\n", i, z.x, z.y);
	}
}


// int	main(void)
// {
// 	Mandelbrot();
// }