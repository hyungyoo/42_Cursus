# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 19:42:55 by hyungyoo          #+#    #+#              #
#    Updated: 2022/01/22 15:05:56 by hyungyoo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= ./main.cpp ./Bureaucrat.cpp ./Form.cpp ./ShrubberyCreationForm.cpp \
				  ./RobotomyRequestForm.cpp ./PresidentialPardonForm.cpp	\
				  ./Intern.cpp

OBJS			= $(SRCS:.cpp=.o)

C				= clang++
RM				= rm -f
CFLAGS		= -Wall -Wextra -Werror -I. -std=c++98  #-g3 -fsanitize=address

NAME			= ex03

all:			$(NAME)

$(NAME):		$(OBJS)
				$(C) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)
				$(RM) target_A_shrubbey

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
