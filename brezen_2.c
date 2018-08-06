/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brezen_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 18:52:07 by ylesik            #+#    #+#             */
/*   Updated: 2018/08/03 18:52:15 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_bres_dy(t_str *p, t_brez brez, int color)
{
	int const	d2 = (brez.dx - brez.dy) << 1;
	int const	d1 = brez.dx << 1;
	int			d;
	int			i;

	if (brez.x1 >= 0 && brez.y1 >= 0 && brez.x1 < W)
		pixel_image(p, brez.x1, brez.y1, color);
	i = 0;
	d = d1 - brez.dy;
	while (++i <= brez.dy)
	{
		brez.y1 += brez.sy;
		if (d > 0)
		{
			d += d2;
			brez.x1 += brez.sx;
		}
		else
			d += d1;
		if (brez.x1 >= 0 && brez.y1 >= 0 && brez.x1 < W)
			pixel_image(p, brez.x1, brez.y1, color);
	}
}

void	ft_bres_dx(t_str *p, t_brez brez, int color)
{
	int const	d2 = (brez.dy - brez.dx) << 1;
	int const	d1 = brez.dy << 1;
	int			d;
	int			i;

	if (brez.x1 >= 0 && brez.y1 >= 0 && brez.x1 < W)
		pixel_image(p, brez.x1, brez.y1, color);
	i = 0;
	d = d1 - brez.dx;
	while (++i <= brez.dx)
	{
		brez.x1 += brez.sx;
		if (d > 0)
		{
			d += d2;
			brez.y1 += brez.sy;
		}
		else
			d += d1;
		if (brez.x1 >= 0 && brez.y1 >= 0 && brez.x1 < W)
			pixel_image(p, brez.x1, brez.y1, color);
	}
}

void	ft_bres(t_str *p, t_brez brez, int color)
{
	brez.dx = my_abs(brez.xy[0] - brez.x1);
	brez.dy = my_abs(brez.xy[1] - brez.y1);
	brez.sx = (brez.xy[0] >= brez.x1 ? 1 : -1);
	brez.sy = (brez.xy[1] >= brez.y1 ? 1 : -1);
	if (brez.dy <= brez.dx)
		ft_bres_dx(p, brez, color);
	else
		ft_bres_dy(p, brez, color);
}
