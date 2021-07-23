/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:55:54 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/07/22 14:55:55 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	ft_stack_free_2(t_stack *stack_a, t_stack *stack_b)
{
	ft_stack_free(stack_a);
	ft_stack_free(stack_b);
}

void	ft_stack_free(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	stack->prev->next = NULL;
	while (stack != NULL)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}
