/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 00:27:02 by acoste            #+#    #+#             */
/*   Updated: 2024/08/03 20:46:17 by acoste           ###   ########.fr       */
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


void	handle_pixel(int x, int y, t_fractol *f)
{
	t_complex	z;
	t_complex	c;
	t_scale		s;
	int			i;
	double			color;

// iterations
	z.x = 0.0;
	z.y = 0.0;
	s.old_min = WIDTH;
	c.x = scale(x, -2, +2, &s); // problem de old.max
	s.old_min = HEIGHT;
	c.x = scale(y, +2, -2, &s); //proble de old max
	printf(RED "PROBLEME DE OLD MAX A MODIFIER" RESET);
	i = 0;
	s.iteration_definition = f->iteration_definition;
	while (i < f->escape_value)//nbr iteration //verif
	{
		// z carre + c;
		z = sum_complexe(square_complex(z), c);
		if ((z.x) * (z.x) + (z.y) * (z.y) > f->escape_value) // the point has escape
		{
			color = scale(i, BLACK, WHITE, &s);
			// printf("---color : %f---", color);
			my_pixel_put(x ,y, &f->img, color);
			return ;
		}
		i++;
	}
	//we are in mandelbrot set
	my_pixel_put(x, y, &f->img, RED);
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
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->ptr, f->win, f->img.img_ptr, x, y);
}