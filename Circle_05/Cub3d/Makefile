# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 16:30:52 by hyungyoo          #+#    #+#              #
#    Updated: 2022/02/08 17:44:24 by ytak             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

INCS = -I./srcs -I./libft -I./mlx
INCLIB = -Lmlx -lmlx -framework OpenGL -framework Appkit -Llibft -lft

LIBFT_D = ./libft
LIBFT_A = ./libft/libft.a
LIBFT_M = ./mlx

FILES = main.c \
		read_map.c \
		check_map.c \
		validate_map.c \
		allocate_map.c	\
		keycode.c		\
		arrange_game.c  \
		execute_game.c  \
		ray_casting.c	\
		strip_texture_color.c \
		ft_strexit.c \

SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_D)
	make -C $(LIBFT_M)
	$(CC) $(CFLAGS) $(INCS) -o $(NAME) $(OBJS) $(INCLIB)

clean:
	make -C $(LIBFT_D) clean
	make -C $(LIBFT_M) clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(LIBFT_A)

re: fclean all

.PHONY: all clean fclean re
