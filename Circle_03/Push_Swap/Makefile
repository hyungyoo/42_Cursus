TARGET		= push_swap

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -rf

INCS_DIR	= ./includes/
SRCS_DIR	= ./srcs/
OBJS_DIR	= ./objs/

SRC			= main.c \
			  ft_split.c \
			  ft_atoi.c \
			  ft_ajouter_node.c \
			  ft_ajouter_node_split.c \
			  ft_free.c \
			  ft_print.c \
			  ft_verifier.c \

SRCS		= $(addprefix $(SRCS_DIR), $(SRC))
OBJS		= $(addprefix $(OBJS_DIR), $(SRC:.c=.o))

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) -I $(INCS_DIR)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@

all : $(TARGET)

clean :
	$(RM) $(OBJS_DIR)

fclean : clean
	$(RM) $(TARGET)

re : clean all

bonus :

.PHONY : all clean fclean re bonus
