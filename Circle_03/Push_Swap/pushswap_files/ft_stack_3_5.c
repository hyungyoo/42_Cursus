/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_3_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:01:20 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/07/22 15:01:21 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_stack_2(t_stack **stack)
{
	if (ft_check_ascending(*stack, 2))
		return ;
	if ((*stack)->num > (*stack)->next->num)
		ft_sa(*stack);
}

void	ft_stack_3(t_stack **stack)
{
	if (ft_check_ascending(*stack, 3))
		return ;
	if ((*stack)->num == ft_min(*stack))
	{
		ft_rra(stack);
		ft_sa(*stack);
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

int	ft_comparer(int num, int min, int max)
{
	if (num == min || num == max)
		return (1);
	return (0);
}

void	ft_enlever_min_max(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_a_max;
	int	stack_a_min;
	int	std;

	stack_a_max = ft_max(*stack_a);
	stack_a_min = ft_min(*stack_a);
	std = (*stack_a)->prev->num;
	while (std != (*stack_a)->num)
	{
		if (ft_comparer((*stack_a)->num, stack_a_min, stack_a_max))
			ft_pb(stack_b, stack_a);
		else
			ft_ra(stack_a);
	}
	if (ft_comparer((*stack_a)->num, stack_a_min, stack_a_max))
		ft_pb(stack_b, stack_a);
}

void	ft_stack_5(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_check_ascending(*stack_a, 5))
		return ;
	ft_enlever_min_max(stack_a, stack_b);
	ft_stack_3(stack_a);
	ft_pa(stack_a, stack_b);
	if ((*stack_a)->num > (*stack_a)->next->num)
	{
		ft_ra(stack_a);
		ft_pa(stack_a, stack_b);
	}
	else
	{
		ft_pa(stack_a, stack_b);
		ft_ra(stack_a);
	}
}
