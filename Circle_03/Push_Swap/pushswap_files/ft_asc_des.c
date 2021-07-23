/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asc_des.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:59:36 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/07/22 14:59:37 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_check_ascending(t_stack *stack, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}

int	ft_check_descending(t_stack *stack, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack->num < stack->next->num)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}
