# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/21 18:30:11 by hyungyoo          #+#    #+#              #
#    Updated: 2021/08/21 18:30:12 by hyungyoo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

PHI_BONUS	= philo_bonus

SRCS = ./src/main.c \
	   ./src/display.c \
	   ./src/init.c \
	   ./src/init2.c \
	   ./src/util.c \
	   ./src/sleep.c \
	   ./src/thread.c \
	   ./src/thread2.c \

SRCS_BONUS = 	

OBJS 		= ${SRCS:.c=.o}
OBJS_B		= ${SRCS_BONUS:.c=.o}

CCG			= gcc -g -fsanitize=address
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -pthread
RM			= rm -f
NAME		= philo

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
			${CC} $(CFLAGS) -o $(NAME) $(OBJS)

$(philo_BONUS):${OBJS_B}
			${CC} ${CFLAGS} -o ${PHI_BONUS} ${OBJS_B}

bonus:		re $(PHI_BONUS)

clean:
			${RM} ${OBJS}  
			${RM} ${OBJS_B}

fclean: 	clean
			${RM} ${NAME}
			${RM} ${PHI_BONUS}

re: 		fclean all

.PHONY:		bonus all clean fclean re
