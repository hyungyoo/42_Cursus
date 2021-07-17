#include "../inc/push_swap.h"

void	ft_sa(t_stack *stack_a)
{
	int	tmp;

	if (!stack_a)
		return ;
	tmp = stack_a->num;
	stack_a->num = stack_a->next->num;
	stack_a->next->num = tmp;
	ft_putstr("sa\n");
}

void	ft_sb(t_stack *stack_b)
{
	int	tmp;

	if (!stack_b)
		return ;
	tmp = stack_b->num;
	stack_b->num = stack_b->next->num;
	stack_b->next->num = tmp;
	ft_putstr("sb\n");
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}
