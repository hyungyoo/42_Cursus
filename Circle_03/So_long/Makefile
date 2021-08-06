# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/27 19:18:48 by hyungyoo          #+#    #+#              #
#    Updated: 2021/08/06 21:02:03 by hyungyoo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SO_BONUS	= so_long_bonus

SRCS =	./src/get_next_line.c \
		./src/get_next_line_utils.c \
		./src/ft_print_error.c \
		./src/ft_map.c \
		./src/ft_map2.c \
		./src/ft_free.c \
		./src/ft_init_xpm.c \
		./src/ft_keypress.c \
		./src/ft_keypress2.c \
		./src/ft_addr.c \
		./src/main.c \

SRCS_BONUS = 	./bonus/get_next_line.c \
				./bonus/get_next_line_utils.c \
				./bonus/ft_print_error.c \
				./bonus/ft_map.c \
				./bonus/ft_map2.c \
				./bonus/ft_free.c \
				./bonus/ft_init_xpm.c \
				./bonus/ft_init_xpm2.c \
				./bonus/ft_keypress.c \
				./bonus/ft_keypress2.c \
				./bonus/ft_addr.c \
				./bonus/ft_addr2.c \
				./bonus/main.c \
				./bonus/ft_itoa.c \
				./bonus/ft_setup_bonus.c \

OBJS 		= ${SRCS:.c=.o}
OBJS_B		= ${SRCS_BONUS:.c=.o}

PATH_MLX	= mlx
CCG			= gcc -g -fsanitize=address
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
NAME		= so_long
FLAGS		= -ldl -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11 -Wl,-rpath=./bass/,-rpath=./mlx/,-rpath=./delay/

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
			make -C $(PATH_MLX)
			${CC} $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS)

$(SO_BONUS):${OBJS_B}
			make -C $(PATH_MLX)
			${CC} ${CFLAGS} -o ${SO_BONUS} ${OBJS_B} $(FLAGS)

bonus:		re $(SO_BONUS)

clean:
			make -C $(PATH_MLX) clean
			${RM} ${OBJS}  
			${RM} ${OBJS_B}

fclean: 	clean
			make -C $(PATH_MLX) clean
			${RM} ${NAME}
			${RM} ${SO_BONUS}

re: 		fclean all

.PHONY:		bonus all clean fclean re
