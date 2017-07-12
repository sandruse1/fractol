/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piximg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 02:50:17 by sandruse          #+#    #+#             */
/*   Updated: 2017/03/01 16:21:39 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_piximg1(int x, int y, int color, t_julia *w)
{
	w->data = mlx_get_data_addr(w->img, &w->bpp, &w->size, &w->end);
	w->p3 = (int*)&w->data[(x * (w->bpp / 8)) + (y * w->size)];
	*w->p3 = color;
}

void	ft_piximg(int x, int y, int color, t_man *w)
{
	w->data = mlx_get_data_addr(w->img, &w->bpp, &w->size, &w->end);
	w->p3 = (int*)&w->data[(x * (w->bpp / 8)) + (y * w->size)];
	*w->p3 = color;
}

void	ft_piximg2(int x, int y, int color, t_ship *w)
{
	w->data = mlx_get_data_addr(w->img, &w->bpp, &w->size, &w->end);
	w->p3 = (int*)&w->data[(x * (w->bpp / 8)) + (y * w->size)];
	*w->p3 = color;
}
