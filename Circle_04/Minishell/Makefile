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

LIB = -L. -lft -lreadline -L /usr/local/opt/readline/lib
#~/.brew/opt/readline/lib  // ecole42 complie
#/usr/local/opt/readline/lib //keulee home complie

INC = -I /usr/local/opt/readline/include
#~/.brew/opt/readline/include // ecole42 complie
#/usr/local/opt/readline/include //keulee home complie

CC = clang

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

LIBFT = libft.a

RM = rm -f

all: $(NAME)

	@printf "\033[38;5;41m"
	@printf "                                                                         \r"
	@printf "################################################\n"
	@printf "#          :::      ::::::::                   #\n"
	@printf "#        :+:      :+:    :+:       keulee      #\n"
	@printf "#      +:+ +:+         +:+          and        #\n"
	@printf "#    +#+  +:+       +#+           hyungyoo     #\n"
	@printf "#  +#+#+#+#+#+   +#+                 as        #\n"
	@printf "#       #+#    #+#                Minishell    #\n"
	@printf "#      ###   ###########                       #\n"
	@printf "################################################\n"
	@printf " \033[0m"

	@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"

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