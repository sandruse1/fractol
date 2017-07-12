/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 13:46:27 by sandruse          #+#    #+#             */
/*   Updated: 2017/03/02 10:34:34 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_norm(void)
{
	ft_putendl("\x1b[31m\tAllowed fractol name :");
	ft_putendl("\x1b[33m\t\t\t\t - Julia -\n\t\t\t\t - Mandelbrot -");
	ft_putendl("\x1b[33m\t\t\t\t - Carpet -");
	ft_putendl("\x1b[33m\t\t\t\t - Ship -");
	exit(0);
}

void	fc_error(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc < 2 || argc > 4)
	{
		ft_putendl("\x1b[31m\tusage: ./fractol [fractol name], [...]");
		exit(0);
	}
	while (argv[i])
	{
		ft_capital(argv[i]);
		if (ft_strcmp(argv[i], "JULIA") == 0 ||
				ft_strcmp(argv[i], "MANDELBROT") == 0 ||
				ft_strcmp(argv[i], "CARPET") == 0 ||
				ft_strcmp(argv[i], "SHIP") == 0)
			i++;
		else
			ft_norm();
	}
}
