/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:06:00 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/13 00:54:17 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* 
 *	1. ft_parsing_cmd : parsing cmd
 *	2. free all
 */
void	ft_printf_parsing_cmd(char **cmd)
{
	int	i;

	if (!cmd)
		return ;
	i = 0;
	while (cmd[i])
	{
		printf("%s\n", cmd[i++]);
	}
}

int	ft_size_node(t_parsing *a)
{
	int	ret;

	ret = 0;
	while (a)
	{
		a = a->next;
		ret++;
	}
	return (ret);
}

void	ft_print_all_node(t_parsing *parsing)
{
	printf("!!!!!!!!!!!size of node!!!!!!!!! = %d\n", ft_size_node(parsing));
	while (parsing)
	{
		printf("cmd == %s\n", (parsing)->cmd);
		printf("access_cmd = %s\n", (parsing)->access_cmd);
		printf("\n");
		printf("cmd_arg :\n");
		ft_printf_parsing_cmd((parsing)->cmd_arg);
		printf("\n");
		printf("flag = %d\n", (parsing)->flag);
		parsing = (parsing)->next;
		printf("\n\n\n\n\n");
	}
}

void	ft_print_node(t_parsing *a)
{
	printf("\n");
	printf("cmd == %s\n", a->cmd);
	printf("access_cmd == %s\n", a->access_cmd);
	printf("\n cmd_arg: \n");
	ft_printf_parsing_cmd(a->cmd_arg);
	printf("\n");
	printf("flag == %d\n", a->flag);
}

void	parsing(char *str)
{
	t_parsing	*parsing;
	char		**split_cmd;

	split_cmd = NULL;
	parsing = NULL;
	//parsing_node = NULL;
	if (!str)
		return ;
	// charck : parsing, quote, dquote
	if (!ft_parsing_cmd(str, &split_cmd))
		return ;
	if (!split_cmd)
		return ;
	/*
	 * to do
	 * ft_parsing_cmd2 --> for struct and for node
	 */
	ft_init_node(&parsing, split_cmd);
	printf("========printf all node==========\n");
	ft_print_all_node(parsing);
}
