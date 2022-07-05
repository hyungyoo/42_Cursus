# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/21 18:30:11 by hyungyoo          #+#    #+#              #
#    Updated: 2022/07/05 19:29:55 by hyungyoo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

SRCS = ./src/main.c \
	   ./src/display.c \
	   ./src/init.c \
	   ./src/init2.c \
	   ./src/util.c \
	   ./src/sleep.c \
	   ./src/thread.c \
	   ./src/thread2.c \

OBJS 		= ${SRCS:.c=.o}

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -pthread
RM			= rm -f
NAME		= philo

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
			${CC} $(CFLAGS) -g -fsanitize=thread -o $(NAME) $(OBJS)


clean:
			${RM} ${OBJS}  
			${RM} ${OBJS_B}

fclean: 	clean
			${RM} ${NAME}
			${RM} ${PHI_BONUS}

re: 		fclean all

.PHONY:		bonus all clean fclean re
