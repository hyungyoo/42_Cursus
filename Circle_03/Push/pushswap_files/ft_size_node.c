/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:01:05 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/07/22 15:01:06 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_size_node(t_stack *stack)
{
	int		size;
	t_stack	*new;

	if (!stack)
		return (0);
	new = stack->prev;
	size = 0;
	while (new != stack)
	{
		size++;
		stack = stack->next;
	}
	return (++size);
}
