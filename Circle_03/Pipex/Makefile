NAME = pipex

SRCS = main.c \
	   ft_split.c \

OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${OBJS} ${CFLAGS} -o ${NAME}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: clean fclean re all
