#include "../inc/push_swap.h"

void	ft_stack_3_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = ft_min(*stack_b);
	if ((*stack_b)->next->num == ft_max(*stack_b))
		ft_sb(*stack_b);
	if ((*stack_b)->num == ft_max(*stack_b))
	{
		ft_pa(stack_a, stack_b);
		if ((*stack_b)->num == min)
			ft_sb(*stack_b);
		ft_pa(stack_a, stack_b);
		ft_pa(stack_a, stack_b);
	}
	else
	{
		ft_pa(stack_a, stack_b);
		ft_sb(*stack_b);
		ft_pa(stack_a, stack_b);
		ft_sa(*stack_a);
		ft_pa(stack_a, stack_b);
		if ((*stack_a)->num != min)
			ft_sa(*stack_a);
	}
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
	int	i;
	int	count_rb;
	int	count_ra;
	int	count_pa;

	count_ra = 0;
	count_rb = 0;
	count_pa = 0;
	i = 0;
	if (ft_return_b_to_a(stack_a, stack_b, count))
		return ;
	pivot = ft_pivot(*stack_b);
	small_pivot = ft_small_pivot(*stack_b);
	while (count--)
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
