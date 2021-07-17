#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0

typedef struct s_stack
{
	int				num;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

/*
 * ft_ajouter_node.c
 */
t_stack		*ft_new_node(char *num);
void		ft_ajouter_node(t_stack **stack, t_stack *node);

/*
 * ft_atoi.c
 */
int			ft_atoi(char *num);

/*
 * ft_free.c
 */
void		ft_stack_free(t_stack *stack);

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

#endif
