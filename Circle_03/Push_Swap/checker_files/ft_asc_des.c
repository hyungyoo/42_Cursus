/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asc_des.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:55:40 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/07/22 14:55:42 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

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
