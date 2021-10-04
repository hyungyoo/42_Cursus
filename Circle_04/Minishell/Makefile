NAME = minishell

SRCS = srcs/minishell.c \
       srcs/parsing/parsing.c  \
       srcs/parsing/quote/quote.c    \
       srcs/exit/exit.c    \
       srcs/util/util.c    \
       srcs/initial/initial.c  \
       srcs/signal/signal.c    \

HEADER = ./includes/minishell.h

OBJS = $(SRCS:.c=.o)

LIB = -L. -lft -lreadline -L ~/.brew/opt/readline/lib
#~/.brew/opt/readline/lib  // ecole42 complie
#/usr/local/opt/readline/lib //keulee home complie
#linux complie ??

INC = -I ~/.brew/opt/readline/include
#~/.brew/opt/readline/include // ecole42 complie
#/usr/local/opt/readline/include //keulee home complie
#linux complie ??

CC = clang

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

LIBFT = libft.a

RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(LIB) $(OBJS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C libft
	mv libft/$(LIBFT) .

.c.o:
		${CC} ${CFLAGS} $(INC) -c $< -o ${<:.c=.o}

#$(OBJS): $(SRCS) $(HEADER)
#	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re%
