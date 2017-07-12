/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 00:40:57 by sandruse          #+#    #+#             */
/*   Updated: 2017/03/01 17:04:59 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_ll(t_window *wind, int n)
{
	void	*image;
	int		y;
	int		i;
	int		j;

	image = mlx_xpm_file_to_image(wind->mlx, "svin1.xpm", &i, &j);
	mlx_put_image_to_window(wind->mlx, wind->win, image, 1250 - i, 590 - j);
	mlx_destroy_image(wind->mlx, image);
	y = 9;
	while (y < n)
	{
		mlx_string_put(wind->mlx, wind->win, 1001, y, 0xFFFFFF,
				"______________________________");
		y = y + 20;
	}
}

void		ft_menu_mandelbrot(t_window *wind)
{
	int		y;

	y = 0;
	ft_ll(wind, 160);
	mlx_string_put(wind->mlx, wind->win, 1015, 5, 0xFFF800,
			"Fractol : MANDELBROT");
	mlx_string_put(wind->mlx, wind->win, 1015, 25, 0x00FF00, "Zoom + : +");
	mlx_string_put(wind->mlx, wind->win, 1015, 45, 0x00FF00, "Zoom - : -");
	mlx_string_put(wind->mlx, wind->win, 1015, 65, 0x00FF00, "Zoom + : MB3");
	mlx_string_put(wind->mlx, wind->win, 1015, 85, 0x00FF00, "Zoom - : MB3");
	mlx_string_put(wind->mlx, wind->win, 1015, 105, 0x00FF00,
			"MOVE   : Arrows");
	mlx_string_put(wind->mlx, wind->win, 1015, 125, 0x00FF00,
			"Color  : A | S | D");
	mlx_string_put(wind->mlx, wind->win, 1015, 145, 0x00FF00, "Exit  : Esc");
	while (y <= 800)
		mlx_pixel_put(wind->mlx, wind->win, 1001, y++, 0xFFFFFF);
}

void		ft_menu_ship(t_window *wind)
{
	int		y;

	y = 0;
	ft_ll(wind, 160);
	mlx_string_put(wind->mlx, wind->win, 1015, 5, 0xFFF800, "Fractol : SHIP");
	mlx_string_put(wind->mlx, wind->win, 1015, 25, 0x00FF00, "Zoom + : +");
	mlx_string_put(wind->mlx, wind->win, 1015, 45, 0x00FF00, "Zoom - : -");
	mlx_string_put(wind->mlx, wind->win, 1015, 65, 0x00FF00, "Zoom + : MB3");
	mlx_string_put(wind->mlx, wind->win, 1015, 85, 0x00FF00, "Zoom - : MB3");
	mlx_string_put(wind->mlx, wind->win, 1015, 105, 0x00FF00,
			"MOVE   : Arrows");
	mlx_string_put(wind->mlx, wind->win, 1015, 125, 0x00FF00,
			"Color  : A | S | D");
	mlx_string_put(wind->mlx, wind->win, 1015, 145, 0x00FF00, "Exit  : Esc");
	while (y <= 800)
		mlx_pixel_put(wind->mlx, wind->win, 1001, y++, 0xFFFFFF);
}

void		ft_menu_julia(t_window *wind)
{
	int		y;

	y = 0;
	ft_ll(wind, 200);
	mlx_string_put(wind->mlx, wind->win, 1015, 5, 0xFFF800, "Fractol : JULIA");
	mlx_string_put(wind->mlx, wind->win, 1015, 25, 0x00FF00, "Zoom + : +");
	mlx_string_put(wind->mlx, wind->win, 1015, 45, 0x00FF00, "Zoom - : -");
	mlx_string_put(wind->mlx, wind->win, 1015, 65, 0x00FF00, "Zoom + : MB3");
	mlx_string_put(wind->mlx, wind->win, 1015, 85, 0x00FF00, "Zoom - : MB3");
	mlx_string_put(wind->mlx, wind->win, 1015, 105, 0x00FF00,
			"MOVE   : Arrows");
	mlx_string_put(wind->mlx, wind->win, 1015, 125, 0x00FF00,
			"Color  : A | S | D");
	mlx_string_put(wind->mlx, wind->win, 1015, 145, 0x00FF00, "Change param :");
	mlx_string_put(wind->mlx, wind->win, 1015, 165, 0x00FF00,
			"by mouse in menu");
	mlx_string_put(wind->mlx, wind->win, 1015, 185, 0x00FF00, "Exit  : Esc");
	while (y <= 800)
		mlx_pixel_put(wind->mlx, wind->win, 1001, y++, 0xFFFFFF);
}

void		ft_menu(t_window *wind)
{
	int		y;

	y = 0;
	ft_ll(wind, 60);
	mlx_string_put(wind->mlx, wind->win, 1015, 5, 0xFFF800, "Fractol : CARPET");
	mlx_string_put(wind->mlx, wind->win, 1015, 25, 0x00FF00,
			"Color  : A | S | D");
	mlx_string_put(wind->mlx, wind->win, 1015, 45, 0x00FF00, "Exit  : Esc");
	while (y <= 800)
		mlx_pixel_put(wind->mlx, wind->win, 1001, y++, 0xFFFFFF);
}
