/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 17:39:21 by sandruse          #+#    #+#             */
/*   Updated: 2017/03/01 19:13:08 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <pthread.h>

void			ft_if_man(t_man **man, int i)
{
	(*man)->x = i * 125;
	(*man)->xb = i * 125;
	(*man)->y = -1;
	(*man)->xe = i * 125 + 125;
	(*man)->p1 = i * 125;
	(*man)->p2 = 0;
	(*man)->z = 1;
	(*man)->mx = -0.5;
	(*man)->my = 0;
	(*man)->ye = 800;
	(*man)->y = -1;
	(*man)->k = 8;
	(*man)->n = 0.0025;
}

void			ft_tozero(t_man **m)
{
	(*m)->nr = 0;
	(*m)->newim = 0;
	(*m)->oldre = 0;
	(*m)->om = 0;
	(*m)->i = -1;
}

void			*ft_color_m(void *man)
{
	t_man		*j1;

	j1 = *(t_man **)man;
	while (++j1->y < j1->ye)
	{
		j1->x = j1->xb;
		while (j1->x < j1->xe)
		{
			j1->pr = 1.5 * (j1->x - 1000 / 2) / (0.5 * j1->z * 1000) + j1->mx;
			j1->pi = (j1->y - 800 / 2) / (0.5 * j1->z * 800) + j1->my;
			ft_tozero(&j1);
			while (++j1->i < 800)
			{
				j1->oldre = j1->nr;
				j1->om = j1->newim;
				j1->nr = (j1->oldre * j1->oldre) - (j1->om * j1->om) + j1->pr;
				j1->newim = (2 * j1->oldre * j1->om) + j1->pi;
				if (((j1->nr * j1->nr) + (j1->newim * j1->newim)) > 4)
					break ;
			}
			j1->i = j1->i << j1->k;
			ft_piximg(j1->x++, j1->y, j1->i, j1);
		}
	}
	pthread_exit(NULL);
}

void			ft_popo1(t_man **jul)
{
	void		*img;
	pthread_t	*id;
	int			i;

	i = -1;
	img = mlx_new_image(jul[0]->mlx, 1000, 800);
	while (++i < 8)
		jul[i]->img = img;
	id = (pthread_t*)malloc(sizeof(pthread_t) * 8);
	i = -1;
	while (++i < 8)
		pthread_create(&id[i], NULL, ft_color_m, &jul[i]);
	i = 0;
	while (i < 8)
		pthread_join(id[i++], NULL);
	mlx_put_image_to_window(jul[0]->mlx, jul[0]->win, jul[0]->img, 0, 0);
	mlx_destroy_image(jul[0]->mlx, jul[0]->img);
}

void			fc_man(void)
{
	t_window	*wind;
	t_man		**jul;
	int			i;

	i = 0;
	fc_window(&wind, "MANDELBROT");
	jul = (t_man**)malloc(sizeof(t_man*) * 8);
	while (i < 8)
	{
		jul[i] = (t_man*)malloc(sizeof(t_man));
		jul[i]->mlx = wind->mlx;
		jul[i]->win = wind->win;
		ft_if_man(&jul[i], i);
		i++;
	}
	ft_popo1(jul);
	ft_menu_mandelbrot(wind);
	mlx_mouse_hook(wind->win, ft_mouse_clik_m, &jul);
	mlx_hook(wind->win, 2, 3, ft_key_man, &jul);
	mlx_loop(wind->mlx);
}
