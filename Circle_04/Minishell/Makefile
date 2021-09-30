NAME = minishell

SRCS = 	srcs/minishell.c \
		srcs/parsing/parsing.c	\
		srcs/parsing/quote.c	\
		srcs/exit/exit.c	\
		srcs/util/util.c	\
		srcs/initial/initial.c	\

HEADER = ./includes/minishell.h

OBJS = $(SRCS:.c=.o)

IB = -L. -lft -lreadline -L /Users/$(USER)/.brew/opt/readline/lib -I /Users/$(USER)/.brew/opt/readline/include
LIB = -L. -lft -lreadline -L ~/.brew/opt/readline/lib 

#/usr/local/opt/readline/lib //keulee home complie

INC = -I /usr/local/opt/readline/include
#~/.brew/opt/readline/include // ecole42 complie
#/usr/local/opt/readline/include //keulee home complie

CC = clang

CFLAGS = -Wall -Wextra -Werror 

LIBFT = libft.a

RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(LIB) $(OBJS) -o $(NAME) 

$(LIBFT):
	$(MAKE) -C libft
	mv libft/$(LIBFT) .

$(OBJS): ${SRCS:.c=.o}

clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
