/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 20:05:18 by ylesik            #+#    #+#             */
/*   Updated: 2018/07/19 20:05:19 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	*ft_comand_threads(void *pot)
{
	t_threads	*potok;
	int			x;
	int			y;
	int			y_max;

	potok = (t_threads*)pot;
	y = (H / N) * potok->n;
	y_max = H / N * (potok->n + 1);
	x = (W / N) * -1;
	ft_mandelbrot(potok->f, x, y, y_max);
	pthread_exit(0);
}

void			ft_threads(t_str *f)
{
	t_threads		potok[N];
	int				i;
	int				n;

	n = -3;
	i = -1;
	while (++i < N)
	{
		++n;
		potok[i].f = f;
		potok[i].n = n;
		pthread_create(&potok[i].threads, NULL, ft_comand_threads, &potok[i]);
	}
	i = -1;
	while (++i < N)
		pthread_join(potok[i].threads, NULL);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
}
