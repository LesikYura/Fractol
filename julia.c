/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:24:06 by ylesik            #+#    #+#             */
/*   Updated: 2018/07/22 15:24:36 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia_asigned(t_str *f)
{
	f->depth = 50;
	f->x_move = 0.0;
	f->y_move = 0.0;
	f->max = 9;
	f->zoom = 0.007145;
	f->y_move = 0.005;
	f->x_move = 0.005;
	f->mx = W / 2;
	f->my = H / 2;
	f->c_x = 0.11;
	f->c_y = -0.66;
	f->j_cof = 0.723;
}

void	ft_julia_draw_help(t_var2 *j, t_str *f)
{
	j->t_x = j->z_x * f->j_cof;
	j->t_y = j->z_y * f->j_cof;
	j->z_x = j->t_x * j->t_x - j->t_y * j->t_y + f->c_x;
	j->z_y = 2 * j->t_x * j->t_y + f->c_y;
	j->z_x = j->z_x + f->c_x;
	j->z_y = j->z_y + f->c_y;
	j->n++;
}

int		ft_julia_draw(t_str *f)
{
	t_var2 j;

	j.y = -f->my;
	while (j.y < f->my)
	{
		j.x = -f->mx;
		while (j.x < f->mx)
		{
			j.n = 0;
			j.z_x = (j.x * f->zoom * H * 0.001) + (f->y_move * f->zoom);
			j.z_y = (j.y * f->zoom * W * 0.001) + (f->x_move * f->zoom);
			while (j.z_x * j.z_x + j.z_y * j.z_y < f->max && j.n < f->depth)
				ft_julia_draw_help(&j, f);
			if (j.n < f->depth)
				pixel_image(f, f->mx + j.x, f->my + j.y, f->max
				- (j.n % f->max));
			else
				pixel_image(f, f->mx + j.x, f->my + j.y, j.n + 10 * j.n);
			j.x++;
		}
		j.y++;
	}
	return (0);
}
