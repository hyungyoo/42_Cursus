SRCS	=	main.cpp\
			Bureaucrat.cpp\
			Form.cpp\
			ShrubberyCreationForm.cpp\
			RobotomyRequestForm.cpp\
			PresidentialPardonForm.cpp

OBJS	= $(SRCS:.cpp=.o)
NAME	= ex02
CXX		= clang++
CXXFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

debug	:
		$(CXX) $(CXXFLAGS) -fsanitize=address -std=c++98 -Wshadow $(SRCS) -o $(NAME)

clean	:
			$(RM) $(OBJS)

fclean	:
			$(RM) $(NAME) $(OBJS)

re		: fclean all

.PHONY	: all clean fclean re
