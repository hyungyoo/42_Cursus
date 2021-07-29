SERVER = server
CLIENT = client

SRCS_SERVER = server.c \


SRCS_CLIENT = client.c \
	


OBJS_SERVER = ${SRCS_SERVER:.c=.o}
OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: ${SERVER} ${CLIENT}

${SERVER}: ${OBJS_SERVER}
	@${CC} ${OBJS_SERVER} ${CFLAGS} -o ${SERVER}

${CLIENT}: ${OBJS_CLIENT}
	@${CC} ${OBJS_CLIENT} ${CFLAGS} -o ${CLIENT}

clean:
	@${RM} ${OBJS_SERVER}
	@${RM} ${OBJS_CLIENT}

fclean: clean
	@${RM} ${SERVER}
	@${RM} ${CLIENT}

re: fclean all

.PHONY: clean fclean re all
