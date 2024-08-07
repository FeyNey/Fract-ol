/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:46:15 by acoste            #+#    #+#             */
/*   Updated: 2024/08/07 17:21:15 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	close_handler(t_fractol *f)
{
	mlx_destroy_image(f->ptr, f->img.img_ptr);
	mlx_destroy_window(f->ptr, f->win);
	mlx_destroy_display(f->ptr);
	free(f->ptr);
	exit(EXIT_SUCCESS);
}

int	key_handle(int keysym, t_fractol *f)
{
	if (keysym == 65307)
		close_handler(f);
	else if (keysym == 65362 || keysym == 119)
		f->shift_y += (0.5 * f->zoom);
	else if (keysym == 65364 || keysym == 115)
		f->shift_y -= (0.5 * f->zoom);
	else if (keysym == 65361 || keysym == 97)
		f->shift_x -= (0.5 * f->zoom);
	else if (keysym == 65363 || keysym == 100)
		f->shift_x += (0.5 * f->zoom);
	else if (keysym == 65451 || keysym == 120)
		f->iteration_definition += 3;
	else if (keysym == 65453 || keysym == 122)
		f->iteration_definition -= 3;
	else if (keysym == 113)
		f->zoom *= 1.05;
	else if (keysym == 99)
		f->color_shift += 10;
	else if (keysym == 118)
		f->color_shift -= 10;
	else if (keysym == 101)
		f->zoom *= 0.95;
	fractol_render(f);
	return (0);
}

// keysym == 65362 || keysym == 119) haut
// keysym == 65364 || keysym == 115) bas
// keysym == 65361 || keysym == 97) gauche
// keysym == 65363 || keysym == 100) droit
// keysym == 65451 || keysym == 120) plus
// keysym == 65453 || keysym == 122) moins

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
	fractol_render(f);
	return (0);
}

//zoom in, mouse roll frontward
//zoom out, mouse roll backward

/*
int	mouse_track(int x, int y, t_fractol *f)
{
	t_scale s;

	s.old_min = 0;
	if (ft_strcmp (f->name, "julia") == 0)
	{
		s.old_max = WIDTH;
		f->arg_x = (scale(x, -2, +2, &s) * f->zoom) + f->shift_x;
		s.old_max = HEIGHT;
		f->arg_y = (scale(y, +2, -2, &s) * f->zoom) + f->shift_y;
	}
	// fractol_render(f, &f->name);
	return (0);
} */