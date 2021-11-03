/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:00:19 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/03 19:41:17 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_cmd(t_node *cmd)
{
	t_node	*tmp;

	if (!cmd)
		return ;
	while (cmd)
	{
		tmp = cmd->next;
		free(cmd->str);
		free(cmd);
		cmd = tmp;
	}
}

int	ft_check_num_exit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_is_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
 *	1. exit 두개이상인자이면, too many arguments 인지
 *	2. 숫자가 아닌 다른 이자가 들어와도 괜찮은지
 */
void	ft_exit_builtin(t_node **cmd, t_cmd *cmd_start)
{
	int	exit_code ;

	exit_code = 0;
	if ((*cmd)->next)
	{
		while ((*cmd) && (*cmd)->type != ARG)
			(*cmd) = (*cmd)->next;
		if (ft_check_num_exit((*cmd)->str))
		{
			exit_code = ft_atoi((*cmd)->str);
			if (exit_code < 0)
				exit_code *= -1;
			if (exit_code > 255)
				exit_code = exit_code % 255;
		}
		else
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd((*cmd)->str, 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			g_info.exit_code = 255;
			return ;
		}
	}
	ft_putendl_fd("\033[38;5;31mminishell exit \033[0m", 2);
	ft_exit_minishell(exit_code, &(cmd_start));
}
