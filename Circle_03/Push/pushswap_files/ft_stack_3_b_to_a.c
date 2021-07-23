/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_3_b_to_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:01:27 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/07/22 15:01:28 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_min_size(t_stack *stack, int size)
{
	int	i;
	int	min;

	i = 0;
	min = stack->num;
	while (i < size)
	{
		if (min > stack->num)
			min = stack->num;
		i++;
		stack = stack->next;
	}
	return (min);
}

int	ft_max_size(t_stack *stack, int size)
{
	int	i;
	int	max;

	i = 0;
	max = stack->num;
	while (i < size)
	{
		if (max < stack->num)
			max = stack->num;
		i++;
		stack = stack->next;
	}
	return (max);
}
