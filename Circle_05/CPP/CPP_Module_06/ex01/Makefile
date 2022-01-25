# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 19:42:55 by hyungyoo          #+#    #+#              #
#    Updated: 2022/01/25 05:26:45 by hyungyoo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= ./main.cpp ./Serialization.cpp

OBJS			= $(SRCS:.cpp=.o)

C				= clang++
RM				= rm -f
CFLAGS		= -Wall -Wextra -Werror -I. -std=c++98  #-g3 -fsanitize=address

NAME			= serialization

all:			$(NAME)

$(NAME):		$(OBJS)
				$(C) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
