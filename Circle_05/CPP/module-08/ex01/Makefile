SRCS	=	main.cpp\
			span.cpp

OBJS	= $(SRCS:.cpp=.o)
NAME	= ex01
CXX		= clang++
CXXFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

debug	:
		$(CXX) $(CXXFLAGS) -fsanitize=address -std=c++03 $(SRCS) -o $(NAME)

clean	:
			$(RM) $(OBJS)

fclean	:
			$(RM) $(NAME) $(OBJS)

re		: fclean all

.PHONY	: all clean fclean re
