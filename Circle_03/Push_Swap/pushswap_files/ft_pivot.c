/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pivot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:00:25 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/07/22 15:00:26 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	*ft_table(t_stack *stack, int size_table)
{
	int	*table;
	int	i;

	i = 0;
	table = (int *)malloc(sizeof(int) * size_table);
	if (!table)
		return (0);
	while (i < size_table)
	{
		table[i] = stack->num;
		stack = stack->next;
		i++;
	}
	return (table);
}

/*
 *	여기는 내부 while을 들어내야할듯함
 */
int	ft_small_pivot(t_stack *stack, int size_node)
{
	int	*table;
	int	i;
	int	j;
	int	count;
	int	ret;

	table = ft_table(stack, size_node);
	i = -1;
	while (++i < size_node)
	{
		j = 0;
		count = 0;
		while (j < size_node)
			if (table[i] > table[j++])
				count++;
		if (count == (int)((size_node / 4) + 0.5))
		{
			ret = table[i];
			free(table);
			return (ret);
		}
	}
	ret = table[0];
	free(table);
	return (ret);
}

int	ft_big_pivot(t_stack *stack, int size_node)
{
	int	*table;
	int	i;
	int	j;
	int	count;
	int	ret;

	table = ft_table(stack, size_node);
	i = -1;
	while (++i < size_node)
	{
		j = 0;
		count = 0;
		while (j < size_node)
			if (table[i] > table[j++])
				count++;
		if (count == (int)((size_node / 4 * 3) + 0.5))
		{
			ret = table[i];
			free(table);
			return (ret);
		}
	}
	ret = table[0];
	free(table);
	return (ret);
}

int	ft_pivot(t_stack *stack, int size_node)
{
	int	*table;
	int	i;
	int	j;
	int	count;
	int	ret;

	table = ft_table(stack, size_node);
	i = -1;
	while (++i < size_node)
	{
		j = 0;
		count = 0;
		while (j < size_node)
			if (table[i] > table[j++])
				count++;
		if (count == size_node / 2)
		{
			ret = table[i];
			free(table);
			return (ret);
		}
	}
	ret = table[0];
	free(table);
	return (ret);
}
