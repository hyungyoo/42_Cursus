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
