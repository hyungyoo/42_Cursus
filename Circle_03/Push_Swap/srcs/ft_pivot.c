#include "../inc/push_swap.h"

int	ft_pivot(t_stack *stack)
{
	int	*table;
	int	i;
	int	j;
	int	count;
	int	size_node;

	size_node = ft_size_node(stack);
	table = (int *)malloc(sizeof(int) * size_node);
	if (!table)
		return (-1);
	i = 0;
	while (i < size_node)
	{
		table[i++] = stack->num;
		stack = stack->next;
	}
	while (i < size_node)
	{
		j = 0;
		count = 0;
		while (j < size_node)
			if (table[i] > table[j++])
				count++;
		if (count == size_node / 2)
		{
			free(table);
			return (table[i]);
		}
		i++;
	}
	free(table);
	return (table[0]);
}
