/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_carpet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 11:59:59 by sandruse          #+#    #+#             */
/*   Updated: 2017/03/01 15:48:10 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_carpet_col(t_window *wind)
{
	int x;
	int y;

	y = 0;
	while (y < 800)
	{
		x = -1;
		while (++x < 1000)
			if (!((x / 1) % 3 == 1 && (y / 1) % 3 == 1) && !((x / 3) % 3 == 1
						&& (y / 3) % 3 == 1) && !((x / 9) % 3 == 1 &&
						(y / 9) % 3 == 1) && !((x / 27) % 3 == 1 &&
							(y / 27) % 3 == 1) && !((x / 81) % 3 == 1 &&
								(y / 81) % 3 == 1))
				mlx_pixel_put(wind->mlx, wind->win, x, y, wind->c);
		y++;
	}
}

int		ft_key_c(int keycode, t_window *wind)
{
	t_window *w;

	w = wind;
	if (keycode == 53)
		exit(0);
	if (keycode >= 0 && keycode <= 3)
	{
		if (keycode == 0)
			wind->c = 0x00EE00;
		else if (keycode == 2)
			wind->c = 0xEE0000;
		else if (keycode == 1)
			wind->c = 0x0000EE;
		else
			wind->c = 0xFFFFFF;
		ft_carpet_col(wind);
	}
	return (0);
}

void	fc_carpet(void)
{
	t_window	*wind;

	fc_window(&wind, "CARPET");
	wind->c = 0xFFFFFF;
	ft_menu(wind);
	ft_carpet_col(wind);
	mlx_hook(wind->win, 2, 3, ft_key_c, wind);
	mlx_loop(wind->mlx);
}
