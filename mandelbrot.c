/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 21:06:31 by ylesik            #+#    #+#             */
/*   Updated: 2018/08/03 21:06:32 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot_asigned(t_str *f)
{
	f->depth = 50;
	f->zoom = 0.4;
	f->x_move = 0.0;
	f->y_move = 0.0;
	f->color = 0;
}

void	ft_mandelbrot_draw(t_str *f, int x, int y, t_var *sv)
{
	sv->cr = ((float)x + (float)f->x_move) / 120.0 * f->zoom;
	sv->zi = 0;
	sv->zr = 0;
	sv->k = 0;
	while (sv->k < f->depth)
	{
		sv->tmp = sv->zr * sv->zr - sv->zi * sv->zi;
		sv->zi = 2 * sv->zr * sv->zi + sv->ci;
		sv->zr = sv->tmp + sv->cr;
		if (sv->zr * sv->zr + sv->zi * sv->zi > 1.0E16)
			break ;
		sv->k++;
	}
	if (sv->k < f->depth)
		pixel_image(f, x + f->j_max, y + f->i_max, sv->k);
	else
		pixel_image(f, x + f->j_max, y + f->i_max, sv->k);
}

int		ft_mandelbrot(t_str *f, int x, int y, int y_max)
{
	t_var sv;

	f->i_max = H / 2;
	f->j_max = W / 2;
	f->y_max = y_max;
	while (y < y_max)
	{
		sv.ci = ((float)y + (float)f->y_move) / 160.0 * f->zoom;
		x = (W / 2) * -1;
		while (x < f->j_max)
		{
			ft_mandelbrot_draw(f, x, y, &sv);
			x++;
		}
		y++;
	}
	return (0);
}
