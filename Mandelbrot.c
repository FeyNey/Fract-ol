/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:59:50 by acoste            #+#    #+#             */
/*   Updated: 2024/08/01 16:31:01 by acoste           ###   ########.fr       */
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
	t_mandelbrot z;
	t_mandelbrot c;
	double tmp_real;

	i = 0;

	z.real = 0;
	z.i = 0;

	c.real = 0.10;
	c.i = 0.4;

	while(i < 42)
	{
		//general formula
		// z = z^2 + c
	tmp_real = (z.real * z.real) - (z.i * z.i);
	z.i = 2 * z.real * z.i;
	z.real = tmp_real;
	z.real += c.real;
	z.i += c.i;
		i++;

	printf("iteration n -> %d real %f imaginary %f\n", i, z.real, z.i);
	}
}


// int	main(void)
// {
// 	Mandelbrot();
// }