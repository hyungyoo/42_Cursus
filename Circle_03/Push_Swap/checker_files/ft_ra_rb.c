#include "../inc/checker.h"

void	ft_ra(t_stack **stack_a)
{
	if (!*stack_a || !stack_a)
		return ;
	*stack_a = (*stack_a)->next;
}

void	ft_rb(t_stack **stack_b)
{
	if (!*stack_b || !stack_b)
		return ;
	*stack_b = (*stack_b)->next;
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a || !stack_a)
		return ;
	*stack_a = (*stack_a)->next;
	if (!*stack_b || !stack_b)
		return ;
	*stack_b = (*stack_b)->next;
}
