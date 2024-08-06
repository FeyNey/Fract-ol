/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:45:34 by acoste            #+#    #+#             */
/*   Updated: 2024/08/06 19:28:32 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "fract-ol.h"

double	ft_atoi_to_double(char *argv)
{
	double	sign;
	long	integer_part;
	double	fractional_part;
	double	pow;

	pow = 1;
	sign = 1;
	integer_part = 0;
	fractional_part = 0;
	if (*argv == '-' || *argv == '+')
	{
		if (*argv == '-')
			sign = sign * (-1);
		argv++;
	}
	while (*argv >= '0' && *argv <= '9')
		integer_part = (integer_part * 10) + (*argv++ - '0');
	if (*argv == '.')
		argv++;
	while(*argv)
	{
		pow /= 10;
		fractional_part = fractional_part + (*argv++ - '0') * pow;
	}
	return ((integer_part + fractional_part) * sign);
}

void	julia_args_check(char **argv, t_fractol *f)
{
	int i;
	int y;

	y = 2;
	i = 0;
	while (argv[y][i])
	{
		if ((argv[y][i] >= 0 && argv[y][i] <= 42) || argv[y][i] == 44
			|| argv[y][i] == 47 || (argv[y][i] >= 58 && argv[y][i] <= 127))
			ft_error(2);
		i++;
	}
	y++;
	i = 0;
	while (argv[y][i])
	{
		if ((argv[y][i] >= 0 && argv[y][i] <= 42) || argv[y][i] == 44
			|| argv[y][i] == 47 || (argv[y][i] >= 58 && argv[y][i] <= 127))
			ft_error(2);
		i++;
	}
	f->arg_x = ft_atoi_to_double(argv[2]);
	f->arg_y = ft_atoi_to_double(argv[3]);
}

void	ft_error(int i)
{
	if (i == 1)
	{
		write(1, "Wrong arguments\n", 16);
		write(1, "Try ./fract-ol mandelbrot | or | julia x y\n", 43);
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
	if (argc == 2 && ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		return ; // verif arg for julia x y = numeric parameters
	}
	else if (argc == 4 && ft_strcmp(argv[1], "julia") == 0)
	{
		julia_args_check(argv, f);
	}
	else if (argc == 2 && ft_strcmp(argv[1], "newton") == 0)
	{
		return ;
	}
	else
	{
		ft_error(1);
	}
}

int main(int argc, char **argv)
{
	t_fractol f;

	f.name = argv[1];
	chekargs(argc, argv, &f);
	fractol_init(&f);
	fractol_render(&f, argv);
	mlx_loop(f.ptr);
}
