/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:41:36 by sandruse          #+#    #+#             */
/*   Updated: 2017/03/01 17:05:41 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_mouse_zoom_ship(t_ship ***j, double b)
{
	t_ship	**jul;
	int		i;

	jul = *j;
	i = -1;
	while (++i < 8)
	{
		jul[i]->z = jul[i]->z * b;
		jul[i]->mx = jul[i]->mx - jul[i]->xmv;
		jul[i]->my = jul[i]->my - jul[i]->ymv;
		jul[i]->n = jul[i]->n / b;
	}
	i = -1;
	while (++i < 8)
		jul[i]->y = -1;
}

int			ft_mouse_clik_s(int button, int x, int y, t_ship ***j)
{
	t_ship	**jul;
	int		i;

	jul = *j;
	i = -1;
	if ((button == 4 || button == 5) && x >= 0 && x < 1000 && y >= 0 && y < 800)
	{
		while (++i < 8)
		{
			jul[i]->xmv = ((double)(500 - x) * jul[i]->n) / 7.00;
			jul[i]->ymv = ((double)(400 - y) * jul[i]->n) / 7.00;
		}
		if (button == 4)
			ft_mouse_zoom_ship(&jul, 1.1);
		else
			ft_mouse_zoom_ship(&jul, 0.9);
		ft_popo2(jul);
	}
	return (0);
}
