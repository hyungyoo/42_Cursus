/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:58:44 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/07/22 14:58:50 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

# define BUFFER_SIZE 1

typedef struct s_stack
{
	int				num;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

int			ft_size_node(t_stack *stack);
/*
 * instruction
 */
void		ft_sa(t_stack *stack_a);
void		ft_sb(t_stack *stack_b);
void		ft_ss(t_stack *stack_a, t_stack *stack_b);
void		ft_pa(t_stack **stack_a, t_stack **stack_b);
void		ft_pb(t_stack **stack_a, t_stack **stack_b);
void		ft_ra(t_stack **stack_a);
void		ft_rb(t_stack **stack_b);
void		ft_rr(t_stack **stack_a, t_stack **stack_b);
void		ft_rra(t_stack **stack_a);
void		ft_rrb(t_stack **stack_b);
void		ft_rrr(t_stack **stack_a, t_stack **stack_b);

/*
 * ft_push_pop.c
 */
t_stack		*ft_pop(t_stack **stack);
void		ft_push(t_stack **stack, t_stack *node);

/*
 * ft_verifier_operation.c
 */
int			ft_strcmp(char *s1, char *s2);
void		ft_operation(t_stack **stack_a, t_stack **stack_b, char *operation);

/*
 * get_next_line.c
 */
int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *src);
char		*ft_strjoin(const char *s1, const char *s2);
int			ft_strchr(const char *s, int c);
char		*ft_substr(const char *str, unsigned int start, size_t len);

/*
 * ft_asc_des.c
 */
int			ft_check_ascending(t_stack *stack, int size);

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
int			ft_atoi_size(char *num);

/*
 * ft_free.c
 */
void		ft_stack_free_2(t_stack *stack_a, t_stack *stack_b);
void		ft_free_split(char **str);
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

/*
 * main.c
 */
void		ft_init_stack(t_stack **stack_a, char **argv);
int			main(int argc, char **argv);

#endif
