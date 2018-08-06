/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 17:11:11 by ylesik            #+#    #+#             */
/*   Updated: 2018/07/20 17:11:12 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_tr_move(int x, int y, t_str *f)
{
	if (f->id == 0 || f->id == 2 || f->id == 3)
	{
		f->x_move += (f->push_last_x - x) * 0.9;
		f->y_move += (f->push_last_y - y) * 0.9;
	}
	if (f->id == 1)
	{
		f->y_move += (f->push_last_x - x);
		f->x_move += (f->push_last_y - y);
	}
	redraw_frame(f);
}

void	pixel_image(t_str *f, int x, int y, int n)
{
	if (x < W && x > 0 && y < H && y > 0)
	{
		if (f->id == 0 || f->id == 1)
		{
			f->img_data[(x * 4) + (y * 4 * W)] = my_abs(f->r + 250 +
			f->color) * n % 255;
			f->img_data[(x * 4) + (y * 4 * W + 1)] = my_abs(f->g
			+ 750) * n % 255;
			f->img_data[(x * 4) + (y * 4 * W + 2)] = my_abs(f->b
			+ 1500) * n % 255;
		}
		else if (f->id == 3 || f->id == 2)
		{
			f->img_data[(x * 4) + (y * 4 * W)] = my_abs(f->r + f->color);
			f->img_data[(x * 4) + (y * 4 * W + 1)] = my_abs(f->g
			+ 255 - f->color);
			f->img_data[(x * 4) + (y * 4 * W + 2)] = my_abs(f->b + 10);
		}
	}
}

void	redraw_frame(t_str *f)
{
	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	ft_bzero(f->img_data, W * H * 4);
	if (f->id == 0)
		ft_threads(f);
	else if (f->id == 1)
		ft_julia_draw(f);
	else if (f->id == 2)
		draw_fern(f);
	else if (f->id == 3)
		pytha_draw(f);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
}
