/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_key_mous.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 17:58:28 by ylesik            #+#    #+#             */
/*   Updated: 2018/08/03 17:58:30 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mouse_hook_4(t_str *f)
{
	if (f->id == 3)
		f->zoom = f->zoom * 1.1;
	else if (f->id == 2)
		f->zoom = f->zoom * 1.1;
	else if (f->id == 0)
		f->zoom = f->zoom * 0.9;
	else if (f->id == 1)
		f->zoom = f->zoom * 0.9;
}

void	mouse_hook_5(t_str *f)
{
	if (f->id == 3)
		f->zoom = f->zoom * 0.9;
	else if (f->id == 2)
		f->zoom = f->zoom * 0.9;
	else if (f->id == 0)
		f->zoom = f->zoom * 1.1;
	else if (f->id == 1)
		f->zoom = f->zoom * 1.1;
}

void	mouse_hook_help(int key, int x, int y, t_str *f)
{
	if (key == 4)
		mouse_hook_4(f);
	else if (key == 5)
		mouse_hook_5(f);
	if (x != y)
		;
}

void	deal_key_help(int key, t_str *f)
{
	if (key == 69 && f->depth < 200)
		f->depth += 25;
	else if (key == 78 && f->depth > 50)
		f->depth -= 25;
	else if (key == 27)
	{
		if (f->id != 1 && f->color > 0)
			f->color -= 3;
		else if (f->id == 1 && f->max > 3)
			f->max -= 1;
	}
	else if (key == 24)
	{
		if (f->id != 1 && f->color < 250)
			f->color += 3;
		else if (f->id == 1 && f->max < 1000)
			f->max += 1;
	}
	redraw_frame(f);
}

void	deal_key_pythagoras(int key, t_str *f)
{
	if (key == 12 && f->angle_n > 1.2)
		f->angle_n -= 0.1;
	else if (key == 13 && f->angle_n < 15)
		f->angle_n += 0.1;
	else if (key == 0 && f->angle_m > 1.2)
		f->angle_m -= 0.1;
	else if (key == 1 && f->angle_m < 15)
		f->angle_m += 0.1;
	else if (key == 18 && f->id == 3)
	{
		if (f->angle_m == 1.45 && f->angle_n == 1.45)
			f->angle_m = 2.01;
		else if (f->angle_m == 2.01 && f->angle_n == 2.01)
			f->angle_m = 4.1;
		else
			f->angle_m = 1.45;
		f->angle_n = f->angle_m;
	}
	redraw_frame(f);
}
