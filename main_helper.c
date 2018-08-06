/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 20:12:29 by ylesik            #+#    #+#             */
/*   Updated: 2018/06/25 20:12:32 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ui_button(t_str *f)
{
	ft_putstr("---------------------------\n");
	ft_putstr("     CONTROL BUTTONS\n");
	ft_putstr("___________________________\n");
	ft_putstr("  mouse scroll - zoom\n");
	ft_putstr("  mouse btn 1  - moving\n");
	ft_putstr("  btn '-', '+' - change color\n");
	ft_putstr("  btn NUM '-', '+' - change depth\n");
	ft_putstr("  btn SPACE - return\n");
	ft_putstr("  Press ESC button to exit\n");
	if (f->id == 3)
	{
		ft_putstr("  btn 1 - change shape\n");
		ft_putstr("  btn Q, W, A, S - change angles\n");
	}
	ft_putstr("___________________________\n");
}

void	ft_assign(t_str *f)
{
	f->w_centr = W / 2;
	f->h_centr = H / 2;
	f->w_diff = 0;
	f->h_diff = 0;
	f->mouse_push = 0;
	f->r = 0xFF0000;
	f->g = 0x00FF00;
	f->b = 0x0000FF;
	ui_button(f);
}
