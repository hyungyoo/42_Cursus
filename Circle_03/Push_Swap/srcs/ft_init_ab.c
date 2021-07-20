#include "../inc/push_swap.h"

void	ft_init_count(int *ra, int *rb, int *pb)
{
	*ra = 0;
	*rb = 0;
	*pb = 0;
}

void	ft_init_pivot(t_stack **stack_a, int count, int *pivot, int *big_pivot)
{
	*pivot = ft_pivot(*stack_a, count);
	*big_pivot = ft_big_pivot(*stack_a, count);
}

void	ft_init_count_ba(int *ra, int *rb, int *pa)
{
	*ra = 0;
	*rb = 0;
	*pa = 0;
}

void	ft_init_pivot_ba(t_stack **stack_b, int count, int *pivot, int *small_pivot)
{
	*pivot = ft_pivot(*stack_b, count);
	*small_pivot = ft_small_pivot(*stack_b, count);
}
