#include "../inc/push_swap.h"

void	ft_stack_free(t_stack *stack)
{
	t_stack	*tmp;

	stack->prev->next = NULL;
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}
