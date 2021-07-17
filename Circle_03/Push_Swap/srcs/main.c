#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	stack_a	= NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		i = 0;
		while (argv[++i])
		{
			if (ft_verifier_argv(argv[i]))
				ft_print_error();
			else if (ft_verifier_split(argv[i]))
				ft_ajouter_node_split(&stack_a, argv[i]);
			else
				ft_ajouter_node(&stack_a, ft_new_node(argv[i]));
		}
	}

	/*
	 * test
	 */
	printf("stack_a\n");
	ft_print_all_node(stack_a);
	printf("size : %d\n\n\n", ft_size_node(stack_a));

	printf("stack_b\n");
	ft_print_all_node(stack_b);
	printf("size : %d\n\n\n", ft_size_node(stack_b));


	/*
	 * test
	 */
	ft_stack_free(stack_a);
	return (0);
}
