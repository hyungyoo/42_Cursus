/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:57:18 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/07/22 14:57:19 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

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
