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

int	ft_pivot(t_stack *stack)
{
	int	*table;
	int	i;
	int	j;
	int	count;
	int	size_node;

	size_node = ft_size_node(stack);
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
			free(table);
			return (table[i]);
		}
		i++;
	}
	free(table);
	return (table[0]);
}
