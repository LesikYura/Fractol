/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 18:21:04 by ylesik            #+#    #+#             */
/*   Updated: 2018/06/01 18:21:05 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define W 1000
# define H 500
# define N 4

# include "mlx.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <pthread.h>

typedef struct	s_str
{
	int			id;
	int			x;
	int			y;

	int			w_centr;
	int			h_centr;
	int			w_diff;
	int			h_diff;

	int			r;
	int			g;
	int			b;

	float		x_move;
	float		y_move;

	void		*win_ptr;
	void		*mlx_ptr;
	void		*img_ptr;

	int			bpp;
	int			endian;
	int			size_line;

	char		*img_data;

	int			i;
	int			j;
	int			m;
	int			f_m;
	int			depth;
	int			i_max;
	int			j_max;
	int			y_max;

	float		zoom;

	int			event;
	int			mouse_push;
	int			push_last_x;
	int			push_last_y;
	int			push_delta_x;
	int			push_delta_y;

	int			iter;
	int			max;
	int			mx;
	int			my;
	float		c_x;
	float		c_y;
	float		j_zoom;

	int			deltax;
	int			deltay;
	int			y_step;
	int			x_step;

	int			color;
	double		angle_n;
	double		angle_m;
	int			p_max;
	float		j_cof;
	double		pi;

	double		fern_x;
	double		fern_y;
	double		t_fern;
	double		fern_p;
	int			fern_i;

}				t_str;

typedef struct	s_threads
{
	t_str		*f;
	pthread_t	threads;
	int			n;

}				t_threads;

typedef struct	s_var
{
	float	zi;
	float	zr;
	float	ci;
	float	cr;
	int		k;
	float	tmp;
}				t_var;

typedef struct	s_var2
{
	int		x;
	int		y;
	int		n;
	float	t_x;
	float	t_y;
	float	z_x;
	float	z_y;
}				t_var2;

typedef struct	s_brez
{
	int			x1;
	int			y1;
	int			xy[2];
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	double		a;
}				t_brez;

int				exit_x(void *par);
int				my_abs(int nb);
void			ft_assign(t_str *f);
void			start_draw(t_str *f);

int				ft_mandelbrot(t_str *f, int x, int y, int y_max);
void			ft_mandelbrot_draw(t_str *f, int x, int y, t_var *sv);
int				ft_julia_draw(t_str *f);
void			pytha_draw(t_str *f);
void			draw_fern(t_str *f);

int				deal_key(int key, t_str *f);
void			redraw_frame(t_str *f);
int				mouse_hook(int key, int x, int y, t_str *f);
int				mouse_button_release(int key, int x, int y, t_str *f);
int				mouse_push_move(int x, int y, t_str *f);
void			mouse_hook_help(int key, int x, int y, t_str *f);
void			deal_key_pythagoras(int key, t_str *f);
void			deal_key_help(int key, t_str *f);

void			ft_threads(t_str *f);

void			pixel_image(t_str *f, int x, int y, int n);
void			ft_tr_move(int x, int y, t_str *f);
void			ft_tr_zoom_mouse(int x, int y, t_str *f);
void			ft_bres(t_str *p, t_brez brez, int color);

void			ft_mandelbrot_asigned(t_str *f);
void			ft_pytha_draw_asigned(t_str *f);
void			ft_julia_asigned(t_str *f);
void			ft_fern_asigned(t_str *f);

#endif
