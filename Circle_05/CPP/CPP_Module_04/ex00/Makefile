NAME			=	Polymorphism
CC				=	clang++
CFLAGS			=	-Wall -Wextra -Werror -std=c++98 #-g -fsanitize=address
RM				=	rm -rf
SRCS			=	./main.cpp ./Animal.cpp ./Dog.cpp

OBJS 			=	${SRCS:.cpp=.o}

.cpp.o:
					$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

all:				$(NAME)

$(NAME):			$(OBJS)
				 	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
					$(RM) ${OBJS}

fclean			:	clean
					$(RM) $(NAME)

re				: 	fclean all

.PHONY: 		all fclean clean re
