#include "../inc/push_swap.h"

void	ft_rra(t_stack **stack_a)
{
	if (!stack_a || !*stack_a)
		return ;
	*stack_a = (*stack_a)->prev;
	ft_putstr("rra\n");
}

void	ft_rrb(t_stack **stack_b)
{
	if (!stack_b || !*stack_b)
		return ;
	*stack_b = (*stack_b)->prev;
	ft_putstr("rrb\n");
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !*stack_a)
		return ;
	*stack_a = (*stack_a)->prev;
	if (!stack_b || !*stack_b)
		return ;
	*stack_b = (*stack_b)->prev;
	ft_putstr("rrr\n");
}
