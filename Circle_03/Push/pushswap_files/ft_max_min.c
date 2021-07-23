/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:00:08 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/07/22 15:00:09 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_max(t_stack *stack)
{
	int	i;
	int	size_node;
	int	max;

	i = 0;
	size_node = ft_size_node(stack);
	max = stack->num;
	while (i < size_node)
	{
		if (max < stack->num)
			max = stack->num;
		stack = stack->next;
		i++;
	}
	return (max);
}

int	ft_min(t_stack *stack)
{
	int	i;
	int	size_node;
	int	min;

	i = 0;
	size_node = ft_size_node(stack);
	min = stack->num;
	while (i < size_node)
	{
		if (min > stack->num)
			min = stack->num;
		stack = stack->next;
		i++;
	}
	return (min);
}
