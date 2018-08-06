/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_key.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 17:25:42 by ylesik            #+#    #+#             */
/*   Updated: 2018/07/15 17:25:42 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		deal_key(int key, t_str *f)
{
	if (key == 53)
		exit_x(f->win_ptr);
	else if (key == 49)
	{
		start_draw(f);
		redraw_frame(f);
	}
	else if (f->id == 3 && (key == 12 || key == 13 || key == 0 ||
	key == 1 || key == 18))
		deal_key_pythagoras(key, f);
	else if (key == 69 || key == 78 || key == 27 || key == 24)
		deal_key_help(key, f);
	return (0);
}

void	ft_save_last_xy(int x, int y, t_str *f)
{
	f->push_last_x = x;
	f->push_last_y = y;
}

int		mouse_hook(int key, int x, int y, t_str *f)
{
	if (key == 4 || key == 5)
	{
		mouse_hook_help(key, x, y, f);
		redraw_frame(f);
	}
	else if (key == 1 && f->mouse_push == 0)
	{
		f->mouse_push = 1;
		ft_save_last_xy(x, y, f);
	}
	return (0);
}

int		mouse_button_release(int key, int x, int y, t_str *f)
{
	if (key == 1 && f->mouse_push == 1)
		f->mouse_push = 0;
	if (x != y)
		return (0);
	return (0);
}

int		mouse_push_move(int x, int y, t_str *f)
{
	if (f->mouse_push == 1 && x > 0 && x < W && y > 0 && y < H)
	{
		ft_tr_move(x, y, f);
		ft_save_last_xy(x, y, f);
	}
	else if (f->id == 1)
	{
		if (x > 0 && x < W && y > 0 && y < H)
		{
			if (my_abs(x - y) * 0.001 < 0.933 && my_abs(x - y) * 0.001 > 0.691)
				f->j_cof = my_abs(x - y) * 0.001;
			else if (my_abs(x - y) * 0.001 < 0.691)
				f->j_cof += 0.002;
			else if (my_abs(x - y) * 0.001 > 0.933)
				f->j_cof -= 0.002;
			redraw_frame(f);
		}
	}
	return (0);
}
