# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 00:18:37 by hyungyoo          #+#    #+#              #
#    Updated: 2021/12/04 16:31:18 by hyungyoo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = srcs/minishell.c \
		srcs/signal/signal.c \
		srcs/copy_env.c \
		srcs/list.c \
		srcs/ascii_logo.c \
		srcs/parsing/parsing_quote.c \
		srcs/parsing/parsing.c \
		srcs/parsing/parsing2.c \
		srcs/parsing/parsing3.c \
		srcs/parsing/parsing_operation_word.c \
		srcs/parsing/get_type_dir.c \
		srcs/parsing/parsing_arg_word.c \
		srcs/parsing/set_detail_type.c \
		srcs/ft_free_exit.c \
		srcs/execute/execute/execute.c \
		srcs/execute/execute/execute2.c \
		srcs/execute/execute/execute3.c \
		srcs/execute/execute/execute4.c \
		srcs/execute/execute/execute5.c \
		srcs/execute/execute_pipe/execute_pipe.c \
		srcs/execute/execute_pipe/execute_pipe2.c \
		srcs/execute/execute_pipe/execute_pipe3.c \
		srcs/execute/execute_pipe/execute_pipe4.c \
		srcs/execute/execute_pipe/execute_pipe5.c \
		srcs/execute/execute_cmd/execute_cmd.c \
		srcs/execute/execute_cmd/execute_cmd2.c \
		srcs/execute/execute_cmd/execute_cmd3.c \
		srcs/execute/execute_cmd/execute_cmd4.c \
		srcs/builtin/ft_built_in.c \
		srcs/builtin/ft_pwd.c \
		srcs/builtin/list_env/ft_node_list_env.c \
		srcs/builtin/list_env/ft_node_list_env2.c \
		srcs/builtin/list_env/ft_node_list_env3.c \
		srcs/builtin/ft_env.c \
		srcs/builtin/export/ft_export.c \
		srcs/builtin/export/ft_export2.c \
		srcs/builtin/export/ft_export3.c \
		srcs/builtin/export/ft_export4.c \
		srcs/builtin/export/ft_export5.c \
		srcs/builtin/unset/ft_unset.c \
		srcs/builtin/unset/ft_unset2.c \
		srcs/builtin/echo/ft_echo.c \
		srcs/builtin/echo/ft_echo2.c \
		srcs/builtin/echo/ft_echo3.c \
		srcs/builtin/echo/ft_echo4.c \
		srcs/builtin/cd/ft_cd.c \
		srcs/builtin/cd/ft_cd2.c \
		srcs/builtin/cd/ft_cd3.c \
		srcs/builtin/cd/ft_cd4.c \
		srcs/builtin/cd/ft_cd5.c \
		srcs/builtin/exit/ft_exit.c \
		srcs/builtin/exit/ft_exit2.c \
		srcs/expansion/expansion.c \
		srcs/expansion/expansion2.c \
		srcs/expansion/expansion3.c \
		srcs/expansion/expansion4.c \
		srcs/expansion/expansion5.c \

HEADER = ./includes/minishell.h

OBJS = $(SRCS:.c=.o)

SRCS_DIR = ./srcs

LIB = -L. -lft -lreadline -L /Users/$(USER)/homebrew/opt/readline/lib
LI = -L. -lft -lreadline -L /usr/local/opt/readline/lib
#~/.brew/opt/readline/lib  // ecole42 complie
#/usr/local/opt/readline/lib //keulee home complie

INC = -I/Users/$(USER)/homebrew/opt/readline/include
IN = -I /usr/local/opt/readline/include
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
	@$(CC) $(CFLAGS) -lncurses $(OBJS) $(LIB) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C libft
	@mv libft/$(LIBFT) .

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@$(MAKE) -C libft clean
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) -C libft fclean
	@$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
