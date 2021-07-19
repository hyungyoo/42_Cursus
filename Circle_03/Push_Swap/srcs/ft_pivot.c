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

int	ft_small_pivot(t_stack *stack, int size_node)
{
	int	*table;
	int	i;
	int	j;
	int	count;
	int	ret;

	table = ft_table(stack, size_node);
	i = 0;
	while (i < size_node)
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
		i++;
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
	i = 0;
	while (i < size_node)
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
		i++;
	}
	ret = table[0];
	free(table);
	return (ret);
}

int	ft_pivot(t_stack *stack, int size_node)
{
	int	arr[size_node];
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < size_node)
	{
		arr[i++] = stack->num;
		stack = stack->next;
	}
	i = 0;
	while (i < size_node)
	{
		j = 0;
		count = 0;
		while (j < size_node)
			if (arr[i] > arr[j++])
				count++;
		if (count == size_node / 2)
			return (arr[i]);
		i++;
	}
	return (arr[0]);
}
/*
int	ft_pivot(t_stack *stack, int size_node)
{
	int	*table;
	int	i;
	int	j;
	int	count;
	int	ret;

	table = ft_table(stack, size_node);
	i = 0;
	while (i < size_node)
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
		i++;
	}
	ret = table[0];
	free(table);
	return (ret);
}
*/
