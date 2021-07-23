/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:01:34 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/07/22 15:01:36 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_enlever_min(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_a_min;

	stack_a_min = ft_min(*stack_a);
	while ((*stack_a)->num != stack_a_min)
		ft_ra(stack_a);
	ft_pb(stack_b, stack_a);
}

void	ft_stack_4(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_check_ascending(*stack_a, 4))
		return ;
	ft_enlever_min(stack_a, stack_b);
	ft_stack_3(stack_a);
	ft_pa(stack_a, stack_b);
}
