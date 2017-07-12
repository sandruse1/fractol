/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 13:45:30 by sandruse          #+#    #+#             */
/*   Updated: 2017/03/02 10:31:54 by sandruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "mlx.h"
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include <math.h>

typedef	struct		s_julia
{
	double			cre;
	double			cim;
	double			nr;
	double			newim;
	double			oldre;
	double			om;
	double			z;
	double			mx;
	double			my;
	double			ymv;
	double			xmv;
	int				x;
	int				xe;
	int				ye;
	int				p1;
	int				p2;
	int				y;
	int				xb;
	double			n;
	int				k;
	int				i;
	int				*p3;
	void			*img;
	char			*data;
	int				bpp;
	int				size;
	int				end;
	void			*mlx;
	void			*win;
}					t_julia;

typedef	struct		s_man
{
	double			cre;
	double			cim;
	double			nr;
	double			newim;
	double			oldre;
	double			om;
	double			z;
	double			mx;
	double			my;
	double			ymv;
	double			xmv;
	double			pr;
	double			pi;
	int				x;
	int				xe;
	int				ye;
	int				p1;
	int				p2;
	int				y;
	int				xb;
	double			n;
	int				k;
	int				i;
	int				*p3;
	void			*img;
	char			*data;
	int				bpp;
	int				size;
	int				end;
	void			*mlx;
	void			*win;
}					t_man;

typedef	struct		s_ship
{
	double			cre;
	double			cim;
	double			nr;
	double			newim;
	double			oldre;
	double			om;
	double			z;
	double			mx;
	double			my;
	double			ymv;
	double			xmv;
	double			pr;
	double			pi;
	int				x;
	int				xe;
	int				ye;
	int				p1;
	int				p2;
	int				y;
	int				xb;
	double			n;
	int				k;
	int				i;
	int				*p3;
	void			*img;
	char			*data;
	int				bpp;
	int				size;
	int				end;
	void			*mlx;
	void			*win;
}					t_ship;

typedef struct		s_window
{
	void			*mlx;
	int				c;
	void			*win;
	t_julia			**j;
	t_man			**m;
	t_ship			**s;
}					t_window;

void				fc_error(int argc, char **argv);
void				fc_map(char **argv, int argc);
void				ft_menu_mandelbrot(t_window *wind);
void				ft_menu_ship(t_window *wind);
void				ft_menu_julia(t_window *wind);
void				ft_menu(t_window *wind);
void				ft_popo(t_julia **jul);
void				ft_popo2(t_ship **jul);
void				ft_popo1(t_man **jul);
void				fc_julia(void);
void				fc_window(t_window **wind, char *s);
void				ft_piximg1(int x, int y, int color, t_julia *w);
void				ft_piximg(int x, int y, int color, t_man *w);
void				ft_piximg2(int x, int y, int color, t_ship *w);
void				ft_zoom_plus(t_julia ***jul);
int					ft_key_julia(int keycode, t_julia ***jul);
int					ft_key_ship(int keycode, t_ship ***jul);
int					ft_change_param_jul(int x, int y, t_julia ***j);
int					ft_mouse_clik_j(int button, int x, int y, t_julia ***j);
int					ft_mouse_clik_m(int button, int x, int y, t_man ***j);
int					ft_mouse_clik_s(int button, int x, int y, t_ship ***j);
void				fc_man(void);
void				fc_ship(void);
void				fc_carpet(void);
int					ft_key_man(int keycode, t_man ***jul);
#endif
