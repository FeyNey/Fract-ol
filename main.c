/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:45:34 by acoste            #+#    #+#             */
/*   Updated: 2024/08/02 00:24:40 by acoste           ###   ########.fr       */
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

void	ft_malloc_error() //may be static
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
		ft_malloc_error;
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

void	fractol_render(t_fractol *f)
{

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

