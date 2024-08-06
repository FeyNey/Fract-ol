/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 00:27:02 by acoste            #+#    #+#             */
/*   Updated: 2024/08/07 00:39:20 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//toutes les fonctions de rendering
//deuxieme partie de mon code

#include "../fractol.h"

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_lenght) + (x * (img->bpp / 8));
	*(unsigned int *)(img->data + offset) = color;
}

void	handle_pixel(int x, int y, t_fractol *f)
{
	if (ft_strcmp(f->name, "mandelbrot") == 0
		|| ft_strcmp(f->name, "Mandelbrot") == 0)
	{
		mandelbrot_render(x, y, f);
	}
	if (ft_strcmp(f->name, "julia") == 0
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

void	fractol_render(t_fractol *f)
{
	int	x;
	int	y;

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
	mlx_put_image_to_window(f->ptr, f->win, f->img.img_ptr, 0, 0);
}
