#include "../inc/push_swap.h"

void	ft_des_to_asc(t_stack **stack_a, t_stack **stack_b)
{
	int	size_node;
	int	i;

	i = 0;
	size_node = ft_size_node(*stack_a);
	if (size_node == 2)
		ft_sa(*stack_a);
	else
	{
		i = size_node;
		while (--i)
			ft_pb(stack_b, stack_a);
		i = size_node;
		while (--i)
		{
			ft_pa(stack_a, stack_b);
			ft_ra(stack_a);
		}
	}
}

void	ft_stack_all(t_stack **stack_a, t_stack **stack_b)
{
	int	size_node;

	size_node = ft_size_node(*stack_a);
	if (ft_check_ascending(*stack_a, size_node))
		return ;
	else if (ft_check_descending(*stack_a, size_node))
		ft_des_to_asc(stack_a, stack_b);
}
/*
 * else
 * ft_a_to_b(stack_a, stack_b, size_node);
 */
