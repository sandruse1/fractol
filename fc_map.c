/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 16:46:08 by sandruse          #+#    #+#             */
/*   Updated: 2017/03/02 10:30:55 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fc_map(char **argv, int argc)
{
	pid_t	child;

	child = fork();
	if (child <= 0)
		if (ft_strcmp(argv[1], "JULIA") == 0)
			fc_julia();
		else if (ft_strcmp(argv[1], "MANDELBROT") == 0)
			fc_man();
		else if (ft_strcmp(argv[1], "CARPET") == 0)
			fc_carpet();
		else
			fc_ship();
	else if (argc == 3)
	{
		if (ft_strcmp(argv[2], "JULIA") == 0)
			fc_julia();
		else if (ft_strcmp(argv[2], "MANDELBROT") == 0)
			fc_man();
		else if (ft_strcmp(argv[2], "CARPET") == 0)
			fc_carpet();
		else
			fc_ship();
	}
}
