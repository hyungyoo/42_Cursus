#include "../inc/push_swap.h"

void	ft_rra_rrb(t_stack **stack_a, t_stack **stack_b, int rra, int rrb)
{
	int	count_rrr;
	int	flag;

	if (rra >= rrb)
	{
		count_rrr = rrb;
		rra = rra - count_rrr;
		flag = 1;
	}
	else
	{
		count_rrr = rra;
		rrb = rrb - count_rrr;
		flag = 0;
	}
	while (count_rrr--)
		ft_rrr(stack_a, stack_b);
	if (flag == 1)
		while (rra--)
			ft_rra(stack_a);
	else
		while (rrb--)
			ft_rrb(stack_b);
}

void	ft_stack_3_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_check_ascending(*stack_a, 3))
		return ;
	if ((*stack_a)->next->next->num == ft_max_size(*stack_a, 3))
	{
		ft_sa(*stack_a);
		return ;
	}
	if ((*stack_a)->num == ft_max_size(*stack_a, 3))
		ft_sa(*stack_a);
	if ((*stack_a)->num == ft_min_size(*stack_a, 3))
	{
		ft_ra(stack_a);
		ft_sa(*stack_a);
		ft_rra(stack_a);
	}
	else
	{
		ft_pb(stack_b, stack_a);
		ft_sa(*stack_a);
		ft_ra(stack_a);
		ft_pa(stack_a, stack_b);
		ft_rra(stack_a);
	}
}

int	ft_return_a_to_b(t_stack **stack_a, t_stack **stack_b, int count)
{
	if (count == 2 && ft_check_descending(*stack_a, count))
		ft_sa(*stack_a);
	if (count == 3 && ft_size_node(*stack_a) == 3)
		ft_stack_3(stack_a);
	else if (count == 3)
		ft_stack_3_a_to_b(stack_a, stack_b);
	
	if (ft_check_ascending(*stack_a, count))
		return (1);
	return (0);
}

void	ft_a_to_b(t_stack **stack_a, t_stack **stack_b, int count)
{
	int	pivot;
	int	big_pivot;
	int	count_ra;
	int	count_rb;
	int	count_pb;

	count_ra = 0;
	count_rb = 0;
	count_pb = 0;
	if (ft_return_a_to_b(stack_a, stack_b, count))
		return ;
	pivot = ft_pivot(*stack_a, count);
	big_pivot = ft_big_pivot(*stack_a, count);
	while (count--)
	{
		if ((*stack_a)->num >= big_pivot)
		{
			count_ra++;
			ft_ra(stack_a);
		}
		else if ((*stack_a)->num < big_pivot)
		{
			count_pb++;
			ft_pb(stack_b, stack_a);
			if ((*stack_b)->num >= pivot)
			{
				count_rb++;
				ft_rb(stack_b);
			}
		}
	}
	ft_rra_rrb(stack_a, stack_b, count_ra, count_rb);
	ft_a_to_b(stack_a, stack_b, count_ra);
	ft_b_to_a(stack_a, stack_b, count_rb);
	ft_b_to_a(stack_a, stack_b, (count_pb - count_rb));
}
