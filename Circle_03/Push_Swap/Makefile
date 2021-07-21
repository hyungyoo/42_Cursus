NAME_CHECKER = checker
NAME_PUSHSWAP = push_swap
FLAGS = -Wall -Wextra -Werror -g
CHECKER_SRCDIR = checker_files
CHECKER_OBJDIR = .obj-checker
PUSHSWAP_SRCDIR = pushswap_files
PUSHSWAP_OBJDIR = .obj-pushswap
EXEDIR = ./

SRC_CHECKER =	main.c \
				get_next_line.c \
				get_next_line_utils.c \
				ft_ajouter_node.c \
				ft_ajouter_node_split.c \
				ft_atoi.c \
				ft_free.c \
				ft_print.c \
				ft_split.c \
				ft_verifier.c \
				ft_verifier_operation.c \
				ft_push_pop.c \
				ft_swap.c \
				ft_pa_pb.c \
				ft_ra_rb.c \
				ft_rra_rrb.c \
				ft_asc_des.c \
				ft_size_node.c \

SRC_PUSHSWAP =	main.c \
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


OBJ_CHECKER = $(SRC_CHECKER:%.c=$(CHECKER_OBJDIR)/%.o)
OBJ_PUSHSWAP = $(SRC_PUSHSWAP:%.c=$(PUSHSWAP_OBJDIR)/%.o)


all: $(EXEDIR)$(NAME_PUSHSWAP)

bonus: re $(EXEDIR)$(NAME_CHECKER)

$(EXEDIR)$(NAME_CHECKER): $(OBJ_CHECKER)
	@$(CC) $(FLAGS) $(OBJ_CHECKER)  -o $(EXEDIR)$(NAME_CHECKER) \

$(EXEDIR)$(NAME_PUSHSWAP): $(OBJ_PUSHSWAP)
	@$(CC) $(FLAGS) $(OBJ_PUSHSWAP)  -o $(EXEDIR)$(NAME_PUSHSWAP) \

$(CHECKER_OBJDIR)/%.o: $(CHECKER_SRCDIR)/%.c
	@mkdir -p $(CHECKER_OBJDIR)
	@$(CC) $(FLAGS) -c -o $@ $<

$(PUSHSWAP_OBJDIR)/%.o: $(PUSHSWAP_SRCDIR)/%.c
	@mkdir -p $(PUSHSWAP_OBJDIR)
	@$(CC) $(FLAGS) -c -o $@ $<


clean:
	@rm -rf $(CHECKER_OBJDIR)
	@rm -rf $(PUSHSWAP_OBJDIR)

fclean: clean
	@rm -f $(EXEDIR)$(NAME_CHECKER)
	@rm -f $(EXEDIR)$(NAME_PUSHSWAP)

re: fclean all


.PHONY: clean fclean re all bonus
