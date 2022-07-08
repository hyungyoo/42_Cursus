# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 00:54:48 by hyungyoo          #+#    #+#              #
#    Updated: 2022/07/08 05:45:07 by hyungyoo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --tool=helgrind
# -g -fsanitize=thread

NAME	= philo_bonus

SRCS = ./src/main.c \
	   ./src/display.c \
	   ./src/init.c \
	   ./src/init2.c \
	   ./src/util.c \
	   ./src/sleep.c \
	   ./src/semaphore.c \

OBJS 		= ${SRCS:.c=.o}

CC			= gcc #-g -fsanitize=thread
CFLAGS		= -Wall -Wextra -Werror -pthread
RM			= rm -f

all: 		${NAME}

.c.o:
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
			@${CC} $(CFLAGS) -o $(NAME) $(OBJS)
			@echo "complie!"

clean:
			@${RM} ${OBJS}  
			@${RM} ${OBJS_B}

fclean: 	clean
			@${RM} ${NAME}
			@${RM} ${PHI_BONUS}

re: 		fclean all

.PHONY:		bonus all clean fclean re
