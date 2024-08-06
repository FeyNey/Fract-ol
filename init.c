/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 00:26:08 by acoste            #+#    #+#             */
/*   Updated: 2024/08/06 17:19:50 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void events_init(t_fractol *f)
{
	mlx_hook(f->win, 2, 1L<<0, key_handle, f); // f? 1.29.30
	mlx_hook(f->win, 4, 1L<<2, mouse_handle, f);
	mlx_hook(f->win, 17, 1L<<17, close_handler, f);
	mlx_hook(f->win, 6, 1L<<6, mouse_track, f);
}

void	ft_malloc_error() //may be static
{
	write(1, "Problems with malloc\n", 21);
	exit(EXIT_FAILURE);
}

void	data_init(t_fractol *f)
{
	f->escape_value = 4;
	f->iteration_definition = 100;
	f->shift_x = 0;
	f->shift_y = 0;
	f->zoom = 1;
}

void	fractol_init(t_fractol *f)
{
	f->ptr = mlx_init();
	if (f->ptr == NULL)
		ft_malloc_error();
	f->win = mlx_new_window(f->ptr, WIDTH, HEIGHT, f->name);
	if (f->win == NULL)
	{
		mlx_destroy_display(f->ptr);
		free(f->ptr);
		ft_malloc_error();
	}
	f->img.img_ptr =  mlx_new_image(f->ptr, WIDTH, HEIGHT);
	if (f->img.img_ptr == NULL)
	{
		mlx_destroy_window(f->win, f->ptr);
		mlx_destroy_display(f->ptr);
		free (f->ptr);
		ft_malloc_error();
	}
	f->img.data = mlx_get_data_addr(f->img.img_ptr, &f->img.bpp,
									&f->img.line_lenght, &f->img.endian); //is parameters initialised ?
	events_init(f);
	data_init(f);
	// HOOK events
}