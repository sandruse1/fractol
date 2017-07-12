# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sandruse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/24 07:18:53 by sandruse          #+#    #+#              #
#    Updated: 2017/03/02 10:26:58 by sandruse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = ft_piximg.c\
	  fc_windo.c\
	  fc_julia.c\
	  fc_main.c\
	  fc_carpet.c\
	  fc_error.c\
	  fc_man.c\
	  fc_map.c\
	  fc_ship.c\
	  ft_julia_event.c\
	  ft_julia_mouse.c\
	  ft_man_event.c\
	  ft_man_mouse.c\
	  ft_menu.c\
	  ft_ship_event.c\
	  ft_ship_mouse.c\

GG = $(SRC: .c=.o)

HEAD = fractol.h

FLAG = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

LIB = libft/libft.a

LIB_HEAD = libft/libft.h

all: $(NAME)

$(NAME):$(GG) $(LIB_HEAD) $(HEAD)
	@echo "\033[33mСтворення бібліотеки...Очікуйте"
	@make -C libft
	@echo "\033[32;01mГотово!)"
	@echo "\033[33mКомпіляція програми"
	@gcc -o $(NAME) $(SRC) $(LIB) $(FLAG) $(MLX)
	@echo "\033[32;01mLet's Get Ready To Rumble\n"
	@echo "\033[37;01mДоступні фрактали : \033[36;01mJulia | Mandelbrot | Ship | Carpet\n"
	@echo "\033[31;01mВи можете відкрити один або два фрактали за раз"
	@echo "\033[33;01mДля цього введіть команду :"
	@echo "\033[33;01m./fractol [Назва фракталу] [Назва фракталу]\n"

clean:
	@rm -f *.o
	@make clean -C libft
	@echo "\033[32mCLEAN OK!)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft
	@echo "\033[32mFCLEAN OK!)"

re: fclean all
