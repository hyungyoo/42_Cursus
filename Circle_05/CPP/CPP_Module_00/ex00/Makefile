# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 17:55:53 by hyungyoo          #+#    #+#              #
#    Updated: 2021/12/07 18:00:21 by hyungyoo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++

CFLAG =  -std=c++98 -Wall -Wextra -Werror

NAME	= megaphone


SRC		= megaphone.cpp

all		: $(NAME)

$(NAME)  :
			$(CC) $(CFLAG) $(SRC) -o $(NAME)

clean	:
			rm -f $(NAME)

fclean	:	clean


re		:	fclean all
