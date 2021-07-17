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
			/*else if (ft_verifier_split(argv[i]))
				ft_ajouter_node_split(&stack_a, ft_new_node_split(argv[i]));*/
			else
				ft_ajouter_node(&stack_a, ft_new_node(argv[i]));
		}
	}
	ft_stack_free(stack_a);
	return (0);
}

/*
 *	메모리 릭 관리
 *	malloc으로 node 만든것 -> 마지막에 그리고 duplicate확인할때 free하는 함수만들기
 *	split 으로 이중배열 만든것 -> 바로 사용후 free하도록
 */

/*
 *  이중 링크드 리스트 구현
 *  구현 후에는 리스트 출력 및 길이구하는 함수
 */
