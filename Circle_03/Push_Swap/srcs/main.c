#include "../inc/push_swap.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_print_error(void)
{
	ft_putstr("Error\n");
	exit(1);
}

int	ft_find_number(char	*number)
{
	/*
	 *	전부다 읽으며, ft_digit함수로 확인
	 *	내부의 값들은 숫자 또는 띄어쓰기여야함
	 *	리턴값이 0이라면 false, 그러므로 
	 *	printf error
	 */
}

void	ft_add_new_node(t_stack *stack, char *number)
{
	/*
	 *	띄어쓰기가있다면, split함수 호출후, atoi로 
	 *	각각을 링크드 리스트로 저장
	 *	각각의 인수로 받아들여졌다면, 바로 atoi 저장
	 */
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc != 1)
	{
		i = 0;
		stack_a = NULL;
		stack_b = NULL;
		while (++argv[i])
		{
			if (!(ft_find_number(argv[i])))
				ft_print_error();
			/*
			 *	ft_find_number 
			 *	return -> int 1/0
			 *	함수안에 들어온 값을 숫자인지 확인하여 반환
			 */
			ft_add_new_node(stack_a, argv[i]);
			i++;
	}
	return (0);
}
