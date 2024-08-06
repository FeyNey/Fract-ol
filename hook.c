/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:46:15 by acoste            #+#    #+#             */
/*   Updated: 2024/08/06 12:13:12 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	close_handler(t_fractol *f)
{
	mlx_destroy_image(f->ptr, f->img.img_ptr);
	mlx_destroy_window(f->ptr, f->win);
	mlx_destroy_display(f->ptr);
	free(f->ptr);
	exit(EXIT_SUCCESS);
}


int key_handle(int keysym, t_fractol *f)
{
	if (keysym == 65307)
	{
		close_handler(f);
	}
	else if (keysym == 65362 || keysym == 119) // haut
		f->shift_y += (0.5 * f->zoom);
	else if (keysym == 65364 || keysym == 115) // bas
		f->shift_y -= (0.5 * f->zoom);
	else if (keysym == 65361 || keysym == 97) // gauche
		f->shift_x -= (0.5 * f->zoom);
	else if (keysym == 65363 || keysym == 100) // droit
		f->shift_x += (0.5 * f->zoom);
	else if (keysym == 65451 || keysym == 120) // plus
		f->iteration_definition += 10;
	else if (keysym == 65453 || keysym == 122) // moins
		f->iteration_definition -= 10;
	else if (keysym == 113)
		f->zoom *= 1.05;
	else if (keysym == 101)
		f->zoom *= 0.95;
	fractol_render(f);
	printf ("%d\n", keysym);
	return (0);
}

// wasd	haut gauche bas droite
// e = zoom in	q = zoom out
// z = -iteration	x = + iteration


int	mouse_handle(int button, int x, int y, t_fractol *f)
{
	if (button == 5)
	{
		f->zoom *= 1.05;
	}
	else if (button == 4)
	{
		f->zoom *= 0.95;
	}
	(void)x;
	(void)y;
	printf ("%d\n",  button);
	fractol_render(f);
	return (0);
}

//zoom in, mouse roll frontward
//zoom out, mouse roll backward