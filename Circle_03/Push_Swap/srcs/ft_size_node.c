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
