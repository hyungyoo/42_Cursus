#include "../inc/push_swap.h"

void	ft_init_stack(t_stack **stack_a, char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (ft_verifier_argv(argv[i]))
			ft_print_error();
		else if (ft_verifier_split(argv[i]))
			ft_ajouter_node_split(stack_a, argv[i]);
		else
			ft_ajouter_node(stack_a, ft_new_node(argv[i]));
	}
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		ft_init_stack(&stack_a, argv);
		if (ft_size_node(stack_a) == 2)
			ft_stack_2(&stack_a);
		else if (ft_size_node(stack_a) == 3)
			ft_stack_3(&stack_a);
	}

	/*
	 * test
	 */

	printf("=========stack_a============\n");
	printf("stack_a size est %d\n", ft_size_node(stack_a));
	ft_print_all_node(stack_a);

	/*
	 * test
	 */

	ft_stack_free(stack_a);
	return (0);
}
