/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 17:11:47 by ylesik            #+#    #+#             */
/*   Updated: 2018/08/03 17:11:49 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	start_draw(t_str *f)
{
	if (f->id == 0)
		ft_mandelbrot_asigned(f);
	else if (f->id == 1)
		ft_julia_asigned(f);
	else if (f->id == 2)
		ft_fern_asigned(f);
	else if (f->id == 3)
		ft_pytha_draw_asigned(f);
	redraw_frame(f);
}

void	usage_help(void)
{
	ft_putstr("  usage: ./fractol fractol_name\n");
	ft_putstr("__________________________________\n");
	ft_putstr("  1: mandelbrot\n");
	ft_putstr("  2: julia\n");
	ft_putstr("  3: fern\n");
	ft_putstr("  4: pythagoras\n");
}

int		ft_name_check(char *name)
{
	if (ft_strcmp("mandelbrot", name) == 0)
		return (0);
	else if (ft_strcmp("julia", name) == 0)
		return (1);
	else if (ft_strcmp("fern", name) == 0)
		return (2);
	else if (ft_strcmp("pythagoras", name) == 0)
		return (3);
	usage_help();
	exit(1);
}

int		main(int argc, char **argv)
{
	t_str f;

	if (argc != 2)
	{
		usage_help();
		return (0);
	}
	f.id = ft_name_check(argv[1]);
	ft_assign(&f);
	f.mlx_ptr = mlx_init();
	f.win_ptr = mlx_new_window(f.mlx_ptr, W, H, argv[1]);
	f.img_ptr = mlx_new_image(f.mlx_ptr, W, H);
	f.img_data = mlx_get_data_addr(f.img_ptr, &f.bpp, &f.size_line, &f.endian);
	f.bpp /= 8;
	start_draw(&f);
	mlx_hook(f.win_ptr, 2, 5, deal_key, &f);
	mlx_hook(f.win_ptr, 17, 1L << 17, exit_x, &f);
	mlx_mouse_hook(f.win_ptr, mouse_hook, &f);
	mlx_hook(f.win_ptr, 6, 1L << 6, mouse_push_move, &f);
	mlx_hook(f.win_ptr, 5, 1L << 3, mouse_button_release, &f);
	mlx_loop(f.mlx_ptr);
	return (0);
}
