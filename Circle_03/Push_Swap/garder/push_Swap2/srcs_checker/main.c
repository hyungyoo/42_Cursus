#include "../inc/checker.h"

int	main(void)
{
	int		r;
	char	*operation;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argv < 2)
		return (0);
	/*
	 * stack을 먼저 만든다
	 */
	ft_init_stack(&stack_a, argv);
	/*
	 * ft_verifier_operation 함수
	 * 만들어진 stack_a 리스트를 이용하여
	 * gnl로 받아진 모든 파라미터들을 operation으로
	 * 받아 작동을 실행한다.
	 */
	operation = NULL;
	while (r = get_next_line(&operation) > 0)
	{
		ft_verifier_operation(operation);
		free(operation);
	}
	ft_verifer_operation(operation);
	free(operation);
	/*
	 * 작동이 끝난후, 함수로 ascending인지 학인후 ko ok출력
	 */
	/*
	 * if (!ft_check_vide(stack_b))
	 *	printf("ko\n or error\n");
	 * if (ft_check_ascending(&stack_a, ft_size_node(stack_a))
	 *  printf("ok\n");
	 * else
	 *	printf("ko\n");
	 */
	return (0);
}
