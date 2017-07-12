/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:08:14 by sandruse          #+#    #+#             */
/*   Updated: 2017/03/01 17:03:19 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_zoom_man(t_man ***j, double b)
{
	t_man	**jul;
	int		i;

	jul = *j;
	i = 0;
	while (i < 8)
	{
		jul[i]->z = jul[i]->z * b;
		if (jul[i]->z < 1)
			jul[i]->z = 1;
		jul[i]->y = -1;
		i++;
	}
}

void		ft_move_man(int keycode, t_man ***j)
{
	t_man	**jul;
	int		i;

	i = -1;
	jul = *j;
	if (keycode == 123)
		while (++i < 8)
			jul[i]->mx = jul[i]->mx + 0.05;
	else if (keycode == 124)
		while (++i < 8)
			jul[i]->mx = jul[i]->mx - 0.05;
	else if (keycode == 125)
		while (++i < 8)
			jul[i]->my = jul[i]->my - 0.05;
	else
		while (++i < 8)
			jul[i]->my = jul[i]->my + 0.05;
	i = -1;
	while (++i < 8)
		jul[i]->y = -1;
}

void		ft_color_man(int keycode, t_man ***j)
{
	t_man	**jul;
	int		i;

	i = -1;
	jul = *j;
	if (keycode == 1)
		while (++i < 8)
			jul[i]->k = 16;
	else if (keycode == 2)
		while (++i < 8)
			jul[i]->k = 32;
	else
		while (++i < 8)
			jul[i]->k = 8;
	i = -1;
	while (++i < 8)
		jul[i]->y = -1;
}

int			ft_key_man(int keycode, t_man ***jul)
{
	if ((keycode >= 0 && keycode < 3) || (keycode >= 123 && keycode <= 126)
			|| keycode == 24 || keycode == 27 || keycode == 53)
	{
		if (keycode == 24)
			ft_zoom_man(jul, 1.1);
		else if (keycode == 27)
			ft_zoom_man(jul, 0.9);
		if (keycode == 53)
			exit(0);
		else if (keycode >= 123 && keycode <= 126)
			ft_move_man(keycode, jul);
		else if (keycode == 1 || keycode == 2 || keycode == 0)
			ft_color_man(keycode, jul);
		ft_popo1(*jul);
	}
	return (0);
}
