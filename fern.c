/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fern.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 16:16:59 by ylesik            #+#    #+#             */
/*   Updated: 2018/07/30 16:16:59 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fern_asigned(t_str *f)
{
	f->depth = 100;
	f->x_move = 0.0;
	f->y_move = 0.0;
	f->zoom = 1;
	f->c_x = 0.11;
	f->c_y = -0.66;
	f->color = 0;
}

void	ft_fern_asigned_help(t_str *f)
{
	f->fern_x = 1.0;
	f->fern_y = 1.0;
	f->fern_i = -1;
}

void	draw_fern_stvol(t_str *f)
{
	f->fern_x = 0.0;
	f->fern_y = 0.16 * f->fern_y;
}

void	draw_fern(t_str *f)
{
	ft_fern_asigned_help(f);
	while (++f->fern_i < H * W)
	{
		f->fern_p = random() / (double)(RAND_MAX);
		f->t_fern = f->fern_x;
		if (f->fern_p <= 0.9)
		{
			f->fern_x = 0.84 * f->fern_x + 0.04 * f->fern_y;
			f->fern_y = 0.04 * f->t_fern + 0.85 * f->fern_y + 1.6;
		}
		else if (f->fern_p < 0.92)
		{
			f->fern_x = 0.20 * f->fern_x - 0.26 * f->fern_y;
			f->fern_y = 0.26 * f->t_fern + 0.212 * f->fern_y + 0.44;
		}
		else if (f->fern_p < 0.99)
		{
			f->fern_x = -0.15 * f->fern_x + 0.28 * f->fern_y;
			f->fern_y = 0.26 * f->t_fern + 0.24 * f->fern_y + 0.44;
		}
		else
			draw_fern_stvol(f);
		pixel_image(f, 320 + (int)(70 * f->zoom * f->fern_x) + 150 - f->x_move,
		470 - (int)(40 * f->zoom * f->fern_y) + 1 - f->y_move, f->fern_i);
	}
}
