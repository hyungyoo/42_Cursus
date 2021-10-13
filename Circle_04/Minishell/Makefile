NAME = minishell

SRCS = srcs/minishell.c \
		srcs/signal.c \
		srcs/copy_env.c \
		srcs/parsing.c \
		srcs/list.c \
		srcs/ascii_logo.c \
		srcs/parsing_quote.c \
		srcs/parsing_operation_word.c \
		srcs/ft_exit.c \
		srcs/parsing_arg_word.c

HEADER = ./includes/minishell.h

OBJS = $(SRCS:.c=.o)

SRCS_DIR = ./srcs

LIB = -L. -lft -lreadline -L ~/.brew/opt/readline/lib 
#/usr/local/opt/readline/lib //keulee home complie

INC = -I ~/.brew/opt/readline/include
#/usr/local/opt/readline/include //keulee home complie

CC = clang

CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

LIBFT = libft.a

RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME) 

$(LIBFT):
	$(MAKE) -C libft
	mv libft/$(LIBFT) .

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
