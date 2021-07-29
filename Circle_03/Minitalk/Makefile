# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/29 03:17:58 by hyungyoo          #+#    #+#              #
#    Updated: 2021/07/29 04:19:44 by hyungyoo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SRCS_SERVER = server.c \
			  utils.c \


SRCS_CLIENT = client.c \
			  utils.c \


OBJS_SERVER = ${SRCS_SERVER:.c=.o}
OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: ${SERVER} ${CLIENT}

${SERVER}: ${OBJS_SERVER}
	@${CC} ${OBJS_SERVER} ${CFLAGS} -o ${SERVER} -I.

${CLIENT}: ${OBJS_CLIENT}
	@${CC} ${OBJS_CLIENT} ${CFLAGS} -o ${CLIENT} -I.

clean:
	@${RM} ${OBJS_SERVER}
	@${RM} ${OBJS_CLIENT}

fclean: clean
	@${RM} ${SERVER}
	@${RM} ${CLIENT}

re: fclean all

.PHONY: clean fclean re all
