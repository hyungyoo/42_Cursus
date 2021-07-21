#include "../inc/checker.h"

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
	char	*line;
	int		r;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		ft_init_stack(&stack_a, argv);
		r = get_next_line(0, &line);
		while (r > 0)
		{
			ft_operation(&stack_a, &stack_b, line);
			free(line);
			r = get_next_line(0, &line);
		}
		free(line);
		if (ft_check_ascending(stack_a, ft_size_node(stack_a)) && !stack_b)
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
		ft_stack_free_2(stack_a, stack_b);
	}
	return (0);
}
