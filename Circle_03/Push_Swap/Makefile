NAME_CHECKER = checker
NAME_PUSHSWAP = push_swap
FLAGS = -Wall -Wextra -Werror -g
CHECKER_SRCDIR = checker_files
CHECKER_OBJDIR = .obj-checker
PUSHSWAP_SRCDIR = pushswap_files
PUSHSWAP_OBJDIR = .obj-pushswap
SHARED_SRCDIR = shared_files
SHARED_OBJDIR = .obj-shared
EXEDIR = ./

RED=\033[0;31m
GREEN=\033[0;32m
CYAN=\033[0;36m
NC=\033[0m # No Color

SRC_CHECKER =	checker.c \


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

SRC_SHARED =	

OBJ_CHECKER = $(SRC_CHECKER:%.c=$(CHECKER_OBJDIR)/%.o)
OBJ_PUSHSWAP = $(SRC_PUSHSWAP:%.c=$(PUSHSWAP_OBJDIR)/%.o)
OBJ_SHARED = $(SRC_SHARED:%.c=$(SHARED_OBJDIR)/%.o)


all: $(EXEDIR)$(NAME_CHECKER) $(EXEDIR)$(NAME_PUSHSWAP)

$(EXEDIR)$(NAME_CHECKER): $(OBJ_CHECKER) $(OBJ_SHARED) $(LIBFT)
	@echo "${GREEN} [ + ] ${NC}Creating checker object files"
	@echo "${GREEN} [ + ] ${NC}Creating shared object files"
	@echo "${GREEN} [ + ] ${NC}Creating checker executable"
	@$(CC) $(FLAGS) $(OBJ_CHECKER) $(OBJ_SHARED) -o $(EXEDIR)$(NAME_CHECKER) \

$(EXEDIR)$(NAME_PUSHSWAP): $(OBJ_PUSHSWAP) $(OBJ_SHARED) $(LIBFT)
	@echo "${GREEN} [ + ] ${NC}Creating push_swap object files"
	@echo "${GREEN} [ + ] ${NC}Creating push_swap executable"
	@$(CC) $(FLAGS) $(OBJ_PUSHSWAP) $(OBJ_SHARED) -o $(EXEDIR)$(NAME_PUSHSWAP) \

$(SHARED_OBJDIR)/%.o: $(SHARED_SRCDIR)/%.c
	@mkdir -p $(SHARED_OBJDIR)
	@$(CC) $(FLAGS) -c -o $@ $<

$(CHECKER_OBJDIR)/%.o: $(CHECKER_SRCDIR)/%.c
	@mkdir -p $(CHECKER_OBJDIR)
	@$(CC) $(FLAGS) -c -o $@ $<

$(PUSHSWAP_OBJDIR)/%.o: $(PUSHSWAP_SRCDIR)/%.c
	@mkdir -p $(PUSHSWAP_OBJDIR)
	@$(CC) $(FLAGS) -c -o $@ $<

.PHONY: clean

clean:
	@echo "${RED} [ - ] ${NC}Deleting checker object files"
	@rm -rf $(CHECKER_OBJDIR)
	@echo "${RED} [ - ] ${NC}Deleting push_swap object files"
	@rm -rf $(PUSHSWAP_OBJDIR)
	@echo "${RED} [ - ] ${NC}Deleting shared object files"
	@rm -rf $(SHARED_OBJDIR)

fclean: clean
	@echo "${RED} [ - ] ${NC}Deleting checker executable"
	@rm -f $(EXEDIR)$(NAME_CHECKER)
	@echo "${RED} [ - ] ${NC}Deleting push_swap executable"
	@rm -f $(EXEDIR)$(NAME_PUSHSWAP)

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader  $(SRC)/*
