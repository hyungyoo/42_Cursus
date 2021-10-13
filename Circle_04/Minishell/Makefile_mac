NAME = minishell

SRCS = srcs/minishell.c \
       srcs/parsing/parsing.c  \
       srcs/parsing/quote/quote.c    \
       srcs/parsing/quote/quote_2.c    \
       srcs/parsing/cmd/cmd.c    \
       srcs/parsing/cmd/split_cmd.c    \
       srcs/exit/exit.c    \
       srcs/util/util.c    \
       srcs/initial/initial.c  \
       srcs/initial/initial_node.c  \
       srcs/signal/signal.c    \

HEADER = ./includes/minishell.h

OBJS = $(SRCS:.c=.o)

LIB = -L. -lft -lreadline -L /usr/local/opt/readline/lib 
LI = -L. -lft -lreadline -L ~/.brew/opt/readline/lib 
#/usr/local/opt/readline/lib //keulee home complie
#linux complie ??

INC = -I /usr/local/opt/readline/include
IN = -I ~/.brew/opt/readline/include 
#/usr/local/opt/readline/include //keulee home complie
#linux complie ??

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

nor:
	norminette -R CheckForbiddenSourceHeader includes srcs libft

re: fclean all

.PHONY: all clean fclean re nor

