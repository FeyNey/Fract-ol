/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:45:34 by acoste            #+#    #+#             */
/*   Updated: 2024/08/07 02:10:08 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	valid_arg(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if ((argv[i] >= 0 && argv[i] <= 6)
			|| (argv[i] >= 14 && argv[i] <= 31)
			|| (argv[i] >= 33 && argv[i] <= 42)
			|| (argv[i] == 47)
			|| (argv[i] >= 58)
			|| (argv[i] == 44)
			|| ((argv[i] == '-' || argv[i] == '+')
				&& (argv[i + 1] <= 47 || argv[i + 1] >= 58))
			|| ((argv[i] == '-' || argv[i] == '+')
				&& (argv[i - 1] >= 47 && argv[i - 1] <= 58))
			|| (argv[i] == '.' && (argv[i + 1] <= 47 || argv[i + 1] >= 58))
			|| (argv[i] == '.' && (argv[i - 1] <= 47 || argv[i - 1] >= 58)))
			ft_error(2);
		i++;
	}
}

void	julia_args_check(char **argv, t_fractol *f)
{
	valid_arg(argv[2]);
	valid_arg(argv[3]);
	f->arg_x = ft_atoi_to_double(argv[2]);
	f->arg_y = ft_atoi_to_double(argv[3]);
}

void	ft_error(int i)
{
	if (i == 1)
	{
		write(1, "Wrong arguments\n", 16);
		write(1, "Try ./fract-ol Mandelbrot | or | Julia x y | or | Newton\n",
			57);
	}
	if (i == 2)
	{
		write(1, "Wrong x or y argument\n", 22);
		write(1, "Try a valid integer to start Julia set\n", 39);
	}
	exit(EXIT_FAILURE);
}

void	chekargs(int argc, char **argv, t_fractol *f)
{
	if ((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		|| ((argc == 2 && ft_strncmp(argv[1], "Mandelbrot", 10) == 0)))
		return ;
	else if ((argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0)
		|| (argc == 4 && ft_strncmp(argv[1], "Julia", 5) == 0))
		julia_args_check(argv, f);
	else if ((argc == 2 && ft_strncmp(argv[1], "newton", 6) == 0)
		|| (argc == 2 && ft_strncmp(argv[1], "Newton", 6) == 0))
		return ;
	else
		ft_error(1);
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (argc != 2 && argc != 4)
		ft_error(1);
	f.name = argv[1];
	chekargs(argc, argv, &f);
	fractol_init(&f);
	fractol_render(&f);
	mlx_loop(f.ptr);
}
