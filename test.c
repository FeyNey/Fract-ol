/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:38:33 by acoste            #+#    #+#             */
/*   Updated: 2024/08/01 23:39:47 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	ft_fract_ol(void)
{
	t_fractol	f;
	int	i;
	int y;

	i = WIDTH * 0.1;
	y = HEIGHT * 0.1;
	(void)y;
	(void)i;

	f.ptr = mlx_init();
	if (f.ptr == NULL)
		exit(EXIT_FAILURE);
	f.win = mlx_new_window(f.ptr, WIDTH, HEIGHT, "frac-ol");
	if (f.win == NULL)
	{
		mlx_destroy_display(f.ptr);
		free(f.ptr);
		exit(EXIT_FAILURE);
	}
	while (y < HEIGHT * 0.9)
	{
		while (i < WIDTH * 0.9)
			{
				mlx_pixel_put(f.ptr, f.win, i, y, 0xff00000);
				i++;
			}
		i = WIDTH * 0.1;
		y++;
	}

	mlx_loop(f.ptr);
	mlx_destroy_window(f.ptr, f.win);
	free(f.win);
	mlx_destroy_display(f.ptr);
	free(f.ptr);
	return ;
}