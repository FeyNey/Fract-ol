/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 00:26:08 by acoste            #+#    #+#             */
/*   Updated: 2024/08/02 00:31:19 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

static void	ft_malloc_error() //may be static
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
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
									&f->img.line_lenght, &f->img.endian);
	// HOOK events
	// events_init
	// data_init
}