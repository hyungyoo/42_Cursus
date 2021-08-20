# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/10 10:42:15 by afoulqui          #+#    #+#              #
#    Updated: 2021/07/30 14:50:20 by afoulqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------------- #
#     VARIABLES     #
# ----------------- #

NAME		=	philo

SRC_LST		=	main.c \
				parse.c \
				routine.c \
				display.c \
				int_utils.c \
				philo_utils.c

SRC_DIR		=	$(shell find srcs -type d)
INC_DIR		=	$(shell find includes -type d)
OBJ_DIR		=	objs/

SRC			=	$(foreach dir, $(SRC_DIR), $(SRC_LST))
OBJ			=	$(addprefix $(OBJ_DIR),$(SRC_LST:%.c=%.o))
HEADERS		=	$(foreach dir, $(INC_DIR), $(wildcard $(dir)/*.h))

vpath %.c $(foreach dir, $(SRC_DIR)/, $(dir):)
vpath %.h $(foreach dir, $(INC_DIR)/, $(dir):)

# ----------------- #
#    COMPILATION    #
# ----------------- #

CC			=	gcc

CFLAG		=	-Wall -Werror -Wextra -g -pthread
IFLAG		=	$(foreach dir, $(INC_DIR), -I $(dir) )

# ----------------- #
#     FUNCTIONS     #
# ----------------- #

$(OBJ_DIR)%.o:%.c $(HEADERS)		
				@mkdir -p $(OBJ_DIR)
				@echo "\033[32mCompilation ... $(foreach file, $< , $(notdir $<))"
				@$(CC) $(CFLAG) $(IFLAG) -o $@ -c $<
				

$(NAME):	$(OBJ)
				@$(CC) $(CFLAG) $(OBJ) $(IFLAG) -o $@
				@echo "\n\t\033[36;1m*.............................*"
				@echo "\n\t*    Compilation $(NAME)    *\t   \033[32;1m--------->>> \033[4;5mComplete\033[0m"
				@echo "\n\t\033[036;1m*.............................*\033[0m\n"

all:		$(NAME)

# ----------------- #
#       CLEAN       #
# ----------------- #

RM			=	rm -rf

clean:	
			@$(RM) $(OBJ_DIR)
			@echo "\033[36;1m $(NAME) ------>>  clean\033[0m\n"

fclean:		clean
			@$(RM) $(NAME)
			@echo "\033[36;1m $(NAME) ------>>  fclean\033[0m\n"

re:			fclean all

.PHONY:		all clean fclean re