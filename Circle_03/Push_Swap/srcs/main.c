#include "../inc/push_swap.h"
#include <stdio.h>

void	ft_putstr(char *str);
void	ft_print_error(void);
int		ft_digit(char c);
int		ft_verifier_argv(char *num);
int		ft_verifier_split(char *num);
void	ft_ajouter_node(t_stack **stack, t_stack *node);
void	ft_ajouter_node_split(t_stack **stack, t_stack *node);
int		ft_atoi(char *num);
char	**ft_split(char *str);
int		main(int argc, char **argv);

char	**ft_split(char *str)
{
	char	**ret;

	return (ret);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_print_error(void)
{
	ft_putstr("Error\n");
	exit(0);
}

int	ft_digit(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

/*
 *	si num est numero ou espace, envoie 1, 
 *	si num n'est pas numero ni esapace, envoie 0
 */

int	ft_verifier_argv(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (!(num[i] == ' ' || num[i] == '-' || ft_digit(num[i])))
			return (1);
		else if (num[i] == '-')
			if (!ft_digit(num[i + 1]))
				return (1);
		i++;
	}
	return (0);
}

int	ft_verifier_split(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (num[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(char *num)
{
	long long	ret;
	int			sign;
	int			i;

	ret = 0;
	i = 0;
	sign = 1;
	if (num[i] == '-' || num[i] == '+')
	{
		if (num[i] == '-')
			sign *= -1;
		i++;
	}
	while (num[i])
	{
		ret = (ret * 10) + (num[i] - '0');
		i++;
	}
	if (sign == -1)
		ret *= -1;
	if (!(ret >= -2147483648 && ret <= 2147483647))
		ft_print_error();
	return ((int)ret);
}

t_stack	*ft_new_node(char *num)
{
	t_stack	*new;
	int		nbr;

	nbr = ft_atoi(num);
	printf("%d\n", nbr);
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->prev = new;
	new->next = new;
	new->num = nbr;
	return (new);
}

void	ft_ajouter_node(t_stack **stack, t_stack *node)
{
}

void	ft_ajouter_node_split(t_stack **stack, t_stack *node)
{
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	if (argc >= 2)
	{
		stack_a = NULL;
		stack_b = NULL;
		i = 0;
		while (argv[++i])
		{
			if (ft_verifier_argv(argv[i]))
				ft_print_error();
			else if (ft_verifier_split(argv[i]))
				ft_ajouter_node_split(&stack_a, ft_new_node(argv[i]));
			else
				ft_ajouter_node(&stack_a, ft_new_node(argv[i]));
		}
	}
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
