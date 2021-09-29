NAME = minishell

SRCS = srcs/minishell.c

HEADER = ./includes/minishell.h

OBJS = $(SRCS:.c=.o)

LIB = -L. -lft -lreadline -L /usr/local/opt/readline/lib 
#~/.brew/opt/readline/lib  // ecole42 complie
#/usr/local/opt/readline/lib //keulee home complie

INC = -I /usr/local/opt/readline/include
#~/.brew/opt/readline/include // ecole42 complie
#/usr/local/opt/readline/include //keulee home complie

CC = clang

CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address

LIBFT = libft.a

RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(LIB) $(OBJS) -o $(NAME) 

$(LIBFT):
	$(MAKE) -C libft
	mv libft/$(LIBFT) .

$(OBJS): $(SRCS) $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re