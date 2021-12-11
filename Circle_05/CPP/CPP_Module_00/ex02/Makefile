# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 19:42:55 by hyungyoo          #+#    #+#              #
#    Updated: 2021/12/11 02:28:21 by hyungyoo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= test.cpp Account.cpp

OBJS			= $(SRCS:.cpp=.o)

C				= clang++
RM				= rm -f
CFLAGS		= -Wall -Wextra -Werror -I. #-g3 -fsanitize=address

NAME			= phonebook

all:			$(NAME)

$(NAME):		$(OBJS)
				$(C) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
