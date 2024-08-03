/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:45:34 by acoste            #+#    #+#             */
/*   Updated: 2024/08/03 16:50:32 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "fract-ol.h"

void	chekargs(int argc, char **argv)
{
	if ((argc == 2 && ft_strcmp(argv[1], "mandelbrot") == 0)
		|| (argc == 4 && ft_strcmp(argv[1], "julia") == 0))
	{
		return ; // verif arg for julia x y = numeric parameters
	}
	else
	{
		write(1, "Wrong arguments\n", 16);
		write(1, "Try ./fract-ol mandelbrot | or | julia x y\n", 43);
		exit(EXIT_FAILURE);
	}
}

void	ft_fract_ol(t_fractol f)
{
	fractol_init(&f);
	fractol_render(&f);
	mlx_loop(f.ptr);
}

int main(int argc, char **argv)
{
	t_fractol f;

	f.name = argv[1];
	chekargs(argc, argv);
	ft_fract_ol(f);
}

