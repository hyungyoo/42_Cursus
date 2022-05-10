
NAME	=	fucking_container

SRCS	=	main.cpp	\

OBJS	=	$(SRCS:.cpp=.o)

INC		=	-I	./inc

CC		=	clang++

FLAG	=	-std=c++98 -Wall -Wextra -Werror #-fsanitize=address -g3

$(NAME):
	$(CC) $(FLAG) $(SRCS) -o $(NAME) $(INC)

all:	$(NAME)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re: fclean all
