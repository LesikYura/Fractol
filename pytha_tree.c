/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pytha_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 17:30:20 by ylesik            #+#    #+#             */
/*   Updated: 2018/07/30 17:30:21 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_pytha_draw_asigned(t_str *f)
{
	f->angle_n = 2.01;
	f->angle_m = 2.01;
	f->p_max = 1;
	f->zoom = 1;
	f->color = 0;
	f->x_move = 0;
	f->y_move = 0;
	f->pi = 3.14159;
}

void	pytha_draw2(t_str *f, double *xy, double l, double a)
{
	t_brez	brez;
	double	xy_tmp[2];

	xy_tmp[0] = xy[0];
	xy_tmp[1] = xy[1];
	if (l > f->p_max)
	{
		brez.x1 = xy_tmp[0];
		brez.y1 = xy_tmp[1];
		l *= 0.7;
		brez.xy[0] = xy_tmp[0] + l * cos(a);
		brez.xy[1] = xy_tmp[1] - l * sin(a);
		ft_bres(f, brez, a);
		xy_tmp[0] = brez.xy[0];
		xy_tmp[1] = brez.xy[1];
		pytha_draw2(f, xy_tmp, l, a + f->pi / f->angle_n);
		pytha_draw2(f, xy_tmp, l, a - f->pi / f->angle_m);
	}
}

void	pytha_draw(t_str *f)
{
	double xy[2];

	xy[0] = 500 - f->x_move;
	xy[1] = 460 - f->y_move;
	pytha_draw2(f, xy, 200 * f->zoom, f->pi / 2);
}
