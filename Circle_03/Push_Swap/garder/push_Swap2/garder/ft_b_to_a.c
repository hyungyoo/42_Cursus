#include "../inc/push_swap.h"

void	ft_stack_3_b_to_a(t_stack **stack_a, t_stack **stack_b)
{	
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	ft_a_to_b(stack_a, stack_b, 3);
}

int	ft_return_b_to_a(t_stack **stack_a, t_stack **stack_b, int count)
{
	if (count == 3)
	{
		ft_stack_3_b_to_a(stack_a, stack_b);
		return (1);
	}
	if (count == 2 && ft_check_ascending(*stack_b, count))
	{
		ft_sb(*stack_b);
		ft_pa(stack_a, stack_b);
		ft_pa(stack_a, stack_b);
		return (1);
	}
	if (ft_check_descending(*stack_b, count))
	{
		while (count--)
			ft_pa(stack_a, stack_b);
		return (1);
	}
	return (0);
}

void	ft_b_to_a(t_stack **stack_a, t_stack **stack_b, int count)
{
	int	pivot;
	int	small_pivot;
	int	count_rb;
	int	count_ra;
	int	count_pa;

	count_ra = 0;
	count_rb = 0;
	count_pa = 0;
	if (ft_return_b_to_a(stack_a, stack_b, count))
		return ;
	pivot = ft_pivot(*stack_b, count);
	small_pivot = ft_small_pivot(*stack_b, count);
	while (count--)
	{
		if ((*stack_b)->num < small_pivot)
		{
			count_rb++;
			ft_rb(stack_b);
		}
		else if ((*stack_b)->num >= small_pivot)
		{
			count_pa++;
			ft_pa(stack_a, stack_b);
			if ((*stack_a)->num < pivot)
			{
				count_ra++;
				ft_ra(stack_a);
			}
		}
	}
	ft_a_to_b(stack_a, stack_b, (count_pa - count_ra));
	ft_rra_rrb(stack_a, stack_b, count_ra, count_rb);
	ft_a_to_b(stack_a, stack_b, count_ra);
	ft_b_to_a(stack_a, stack_b, count_rb);
}