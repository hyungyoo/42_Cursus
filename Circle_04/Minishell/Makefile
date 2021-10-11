NAME = minishell

SRCS_DIR = ./


HEADER_DIR = ./includes

LIBFT_DIR = ./libft

READLINE_DIR = $(shell brew --prefix readline)

MAIN = ${SRCS_DIR}srcs/minishell.c

SRCS_NAME =	srcs/parsing/parsing.c \
			srcs/parsing/quote/quote.c \
			srcs/parsing/cmd/cmd.c \
			srcs/parsing/cmd/split_cmd.c \
			srcs/exit/exit.c \
			srcs/util/util.c \
			srcs/initial/initial.c \
			srcs/initial/initial_node.c \
			srcs/signal/signal.c \

SRCS = ${addprefix ${SRCS_DIR}, ${SRCS_NAME}}

OBJS = ${MAIN:.c=.o}

OBJS += ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I${READLINE_DIR}/include -I${HEADER_DIR} -I${LIBFT_DIR}

RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS} ${HEADER_DIR}
	@${MAKE} -C ${LIBFT_DIR}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L${READLINE_DIR}/lib -lreadline -lhistory -L${LIBFT_DIR} -lft

clean:
	${MAKE} -C ${LIBFT_DIR} clean
	${RM} ${OBJS}

fclean: clean
	${MAKE} -C ${LIBFT_DIR} fclean
	${RM} ${NAME}

re: fclean all

val:
	valgrind --leak-check=full --show-leak-kinds=all ./${NAME}

.PHONY: all clean fclean re val
