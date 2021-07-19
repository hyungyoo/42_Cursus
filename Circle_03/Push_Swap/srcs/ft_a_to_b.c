#include "../inc/push_swap.h"

void	ft_a_to_b(t_stack **stack_a, t_stack **stack_b, int count)
{
	int	pivot;
	int	big_pivot;
	int	i;
	int	count_ra;
	int	count_rb;
	int	count_pb;

	count_ra = 0;
	count_rb = 0;
	count_pb = 0;
	i = 0;
	if  (count < 3)
	{
		if (count == 2)
			ft_stack_2(stack_a);
		return ;
	}
	pivot = ft_pivot(*stack_a);
	big_pivot = ft_big_pivot(*stack_a);
	while (i < count)
	{
		if ((*stack_a)->num >= big_pivot)
		{
			ft_ra(stack_a);
			count_ra++;
		}
		else
		{
			ft_pb(stack_b, stack_a);
			count_pb++;
			if ((*stack_b)->num >= pivot)
			{
				ft_rb(stack_b);
				count_rb++;
			}
		}
		i++;
	}
	i = 0;
	while (i < count_ra)
	{
		ft_rra(stack_a);
		i++;
	}
	i = 0;
	while (i < count_rb)
	{
		ft_rrb(stack_b);
		i++;
	}
	ft_a_to_b(stack_a, stack_b, count_ra);
	ft_b_to_a(stack_a, stack_b, count_rb);
	ft_b_to_a(stack_a, stack_b, count_pb - count_rb);
}
