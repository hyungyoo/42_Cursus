# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keulee <keulee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/19 17:00:13 by keulee            #+#    #+#              #
#    Updated: 2021/10/28 03:06:31 by hyungyoo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_putchar.c ft_putstr.c ft_strlen.c ft_strncmp.c \
	  ft_strdup.c ft_strjoin.c ft_strchr.c ft_substr.c \
	  ft_uppercase.c ft_space.c ft_digit.c \
	  ft_strstr_cub.c ft_only_digit.c \
	  ft_atoi.c ft_strcpy.c ft_strlcpy.c ft_strncpy.c \
	  ft_bzero.c ft_calloc.c ft_itoa.c ft_putstr_fd.c \
	  ft_putchar_fd.c ft_putendl_fd.c ft_strcmp.c ft_is_digit.c\
	  ft_free_tab2.c ft_is_letter.c ft_putnbr.c ft_split.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAG = -Wall -Wextra -Werror
INCLUDE = ./
AR = ar
RC = rc
RMF = rm -f

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRC) -I $(INCLUDE)
	$(AR) $(RC) $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RMF) $(OBJ)

fclean: clean
	$(RMF) $(NAME)

re: fclean all

.PHONY: all clean fclean re
