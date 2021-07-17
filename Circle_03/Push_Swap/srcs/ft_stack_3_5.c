#include "../inc/push_swap.h"

void	ft_stack_3(t_stack **stack)
{
	if (ft_check_ascending(*stack, 3))
		return ;
	if ((*stack)->num == ft_min(*stack))
	{
		ft_ra(stack);
		ft_sa(*stack);
		ft_rra(stack);
	}
	else if ((*stack)->num == ft_max(*stack))
	{
		ft_ra(stack);
		if ((*stack)->next->num == ft_min(*stack))
			ft_sa(*stack);
	}
	else
	{
		if ((*stack)->next->num == ft_min(*stack))
			ft_sa(*stack);
		else
			ft_rra(stack);
	}
}
