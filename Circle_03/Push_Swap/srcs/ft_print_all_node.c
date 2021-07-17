#include "../inc/push_swap.h"


void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void	ft_print_all_node(t_stack *stack)
{
	int		i;
	t_stack *new;

	new = stack->prev;
	i = 1;
	while (new != stack)
	{
		printf("%d eme numero : %d\n", i, stack->num);
		stack = stack->next;
		i++;
	}
	printf("%d eme numero : %d\n", i, stack->num);
}
