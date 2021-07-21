TARGET		= push_swap

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -rf

INCS_DIR	= ./inc/
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
			  ft_print_all_node.c \
			  ft_size_node.c \
			  ft_push_pop.c \
			  ft_pa_pb.c \
			  ft_swap.c \
			  ft_ra_rb.c \
			  ft_rra_rrb.c \
			  ft_asc_des.c \
			  ft_stack_3_5.c \
			  ft_stack_4.c \
			  ft_max_min.c \
			  ft_stack_all.c \
			  ft_a_to_b.c \
			  ft_b_to_a.c \
			  ft_pivot.c \
			  ft_stack_3_b_to_a.c \
			  ft_init_ab.c \

SRCS		= $(addprefix $(SRCS_DIR), $(SRC))
OBJS		= $(addprefix $(OBJS_DIR), $(SRC:.c=.o))

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) -I $(INCS_DIR)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@

all : $(TARGET) $(B_TARGET)

clean :
	$(RM) $(OBJS_DIR)

fclean : clean
	$(RM) $(TARGET)

re : clean all

bonus :

.PHONY : all clean fclean re bonus
