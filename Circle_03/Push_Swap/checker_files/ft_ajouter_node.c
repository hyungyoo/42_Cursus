#include "../inc/checker.h"

t_stack	*ft_new_node(char *num)
{
	t_stack	*new;
	int		nbr;

	nbr = ft_atoi_size(num);
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->prev = new;
	new->next = new;
	new->num = nbr;
	return (new);
}

void	ft_ajouter_node(t_stack **stack, t_stack *node)
{
	if (!stack || !node)
		return ;
	if (!*stack)
		*stack = node;
	else
	{
		(*stack)->prev->next = node;
		node->prev = (*stack)->prev;
		(*stack)->prev = node;
		node->next = *stack;
	}
	if (ft_check_duplicate(*stack))
	{
		ft_stack_free(*stack);
		ft_print_error();
	}
}
