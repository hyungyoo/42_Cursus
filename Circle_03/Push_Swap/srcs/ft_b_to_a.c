#include "../inc/push_swap.h"

void	ft_b_to_a(t_stack **stack_a, t_stack **stack_b, int count)
{
	int	pivot;
	int	small_pivot;
	int	i;
	int	count_rb;
	int	count_ra;
	int	count_pa;

	count_ra = 0;
	count_rb = 0;
	count_pa = 0;
	i = 0;
	if (count < 3)
	{
		if (count == 2)
			ft_stack_2(stack_a);
		while (i < count)
		{
			ft_rrb(stack_b);
			ft_pa(stack_a, stack_b);
			i++;
		}
		return ;
	}
	pivot = ft_pivot(*stack_b);
	small_pivot = ft_small_pivot(*stack_b);
	i = 0;
	while (i < count)
	{
		if ((*stack_b)->num < small_pivot)
		{
			ft_rb(stack_b);
			count_rb++;
		}
		else
		{
			ft_pa(stack_a, stack_b);
			count_pa++;
			if ((*stack_b)->num < pivot)
			{
				ft_ra(stack_a);
				count_ra++;
			}
		}
		i++;
	}
	ft_a_to_b(stack_a, stack_b, count_pa - count_ra);
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
}
