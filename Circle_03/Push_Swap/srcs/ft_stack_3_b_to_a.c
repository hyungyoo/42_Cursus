#include "../inc/push_swap.h"

int		ft_min_size(t_stack *stack, int size)
{
	int	i;
	int	min;
	
	i = 0;
	min = stack->num;
	while (i < size)
	{
		if (min > stack->num)
			min = stack->num;
		i++;
		stack = stack->next;
	}
	return (min);
}

int		ft_max_size(t_stack *stack, int size)
{
	int	i;
	int	max;
	
	i = 0;
	max = stack->num;
	while (i < size)
	{
		if (max < stack->num)
			max = stack->num;
		i++;
		stack = stack->next;
	}
	return (max);
}


