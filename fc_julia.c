/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 17:39:21 by sandruse          #+#    #+#             */
/*   Updated: 2017/03/01 19:11:47 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <pthread.h>

void			ft_if(t_julia **jul, int i)
{
	(*jul)->x = i * 125;
	(*jul)->xb = i * 125;
	(*jul)->y = -1;
	(*jul)->xe = i * 125 + 125;
	(*jul)->p1 = i * 125;
	(*jul)->p2 = 0;
	(*jul)->z = 1;
	(*jul)->cre = -0.7;
	(*jul)->cim = 0.27015;
	(*jul)->mx = 0;
	(*jul)->my = 0;
	(*jul)->ye = 800;
	(*jul)->y = -1;
	(*jul)->k = 8;
	(*jul)->n = 0.0025;
}

void			*ft_color_j(void *jul)
{
	t_julia		*j1;

	j1 = *(t_julia**)jul;
	while (++j1->y < j1->ye)
	{
		j1->x = j1->xb;
		while (j1->x < j1->xe)
		{
			j1->nr = 1.5 * (j1->x - 1000 / 2) / (0.5 * j1->z * 1000) + j1->mx;
			j1->newim = (j1->y - 800 / 2) / (0.5 * j1->z * 800) + j1->my;
			j1->i = -1;
			while (++j1->i < 800)
			{
				j1->oldre = j1->nr;
				j1->om = j1->newim;
				j1->nr = (j1->oldre * j1->oldre) - (j1->om * j1->om) + j1->cre;
				j1->newim = (2 * j1->oldre * j1->om) + j1->cim;
				if (((j1->nr * j1->nr) + (j1->newim * j1->newim)) > 4)
					break ;
			}
			j1->i = j1->i << j1->k;
			ft_piximg1(j1->x++, j1->y, j1->i, j1);
		}
	}
	pthread_exit(NULL);
}

void			ft_popo(t_julia **jul)
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
		pthread_create(&id[i], NULL, ft_color_j, &jul[i]);
	i = 0;
	while (i < 8)
		pthread_join(id[i++], NULL);
	mlx_put_image_to_window(jul[0]->mlx, jul[0]->win, jul[0]->img, 0, 0);
	mlx_destroy_image(jul[0]->mlx, jul[0]->img);
}

void			fc_julia(void)
{
	t_window	*wind;
	t_julia		**jul;
	int			i;

	i = 0;
	fc_window(&wind, "JULIA");
	jul = (t_julia**)malloc(sizeof(t_julia*) * 8);
	while (i < 8)
	{
		jul[i] = (t_julia*)malloc(sizeof(t_julia));
		jul[i]->mlx = wind->mlx;
		jul[i]->win = wind->win;
		ft_if(&jul[i], i);
		i++;
	}
	ft_popo(jul);
	ft_menu_julia(wind);
	mlx_hook(wind->win, 6, 0, ft_change_param_jul, &jul);
	mlx_mouse_hook(wind->win, ft_mouse_clik_j, &jul);
	mlx_hook(wind->win, 2, 3, ft_key_julia, &jul);
	mlx_loop(wind->mlx);
}
