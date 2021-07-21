#include "../inc/checker.h"

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, ft_pop(stack_b));
}

void	ft_pb(t_stack **stack_b, t_stack **stack_a)
{
	ft_push(stack_b, ft_pop(stack_a));
}
