#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

/*
 * ft_a_to_b.c 
 * ft_b_to_a.c
 */

/*
 * ft_pivot.c
 */
int			*ft_table(t_stack *stack, int size_table);
int			ft_pivot(t_stack *stack);

/*
 * ft_stack_all.c
 */
void		ft_stack_all(t_stack **stack_a, t_stack **stack_b);

/*
 * ft_stack_4.c
 */
void		ft_enlever_min(t_stack **stack_a, t_stack **stack_b);
void		ft_stack_4(t_stack **stack_a, t_stack **stack_b);

/*
 * ft_max_min.c
 */
int			ft_max(t_stack *stack);
int			ft_min(t_stack *stack);

/*
 * ft_stack_3_5.c
 */
void		ft_stack_2(t_stack **stack);
void		ft_stack_3(t_stack **stack);
int			ft_comparer(int num, int min, int max);
void		ft_enlever_min_max(t_stack **stack_a, t_stack **stack_b);
void		ft_stack_5(t_stack **stack_a, t_stack **stack_b);

/*
 * ft_asc_des.c
 */
int			ft_check_ascending(t_stack *stack, int size);
int			ft_check_descending(t_stack *stack, int size);

/*
 * ft_rra_rrb.c
 */
void		ft_rra(t_stack **stack_a);
void		ft_rrb(t_stack **stack_b);
void		ft_rrr(t_stack **stack_a, t_stack **stack_b);

/*
 * ft_ra_rb.c
 */
void		ft_ra(t_stack **stack_a);
void		ft_rb(t_stack **stack_b);
void		ft_rr(t_stack **stack_a, t_stack **stack_b);

/*
 * ft_swap.c
 */
void		ft_sa(t_stack *stack_a);
void		ft_sb(t_stack *stack_b);
void		ft_ss(t_stack *stack_a, t_stack *stack_b);

/*
 * ft_pa_pb.c
 */
void		ft_pa(t_stack **stack_a, t_stack **b);
void		ft_pb(t_stack **stack_b, t_stack **a);

/*
 * ft_push_pop.c
 */
t_stack		*ft_pop(t_stack **stack);
void		ft_push(t_stack **stack, t_stack *node);

/*
 * ft_ajouter_node.c
 */
t_stack		*ft_new_node(char *num);
void		ft_ajouter_node(t_stack **stack, t_stack *node);

/*
 * ft_ajouter_node_split.c
 */
void		ft_ajouter_node_split(t_stack **stack, char *num);

/*
 * ft_atoi.c
 */
int			ft_atoi(char *num);

/*
 * ft_free.c
 */
void		ft_stack_free(t_stack *stack);
void		ft_free_split(char **str);

/*
 * ft_print.c
 */
void		ft_putstr(char *str);
void		ft_print_error(void);

/*
 * ft_split.c
 */
int			ft_isspace(char c);
int			count_words(char *str);
char		*malloc_word(char *str);
char		**ft_split(char *str);

/*
 *  ft_verifier.c
 */
int			ft_digit(char c);
int			ft_verifier_argv(char *num);
int			ft_verifier_split(char *num);
int			ft_check_duplicate(t_stack *stack);

/*
 * ft_print_all_node.c
 */
void		ft_print_all_node(t_stack *stack);

/*
 * ft_size_node.c
 */
int			ft_size_node(t_stack *stack);

/*
 * main.c
 */
void		ft_init_stack(t_stack **stack_a, char **argv);
int			main(int argc, char **argv);

#endif
