/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:00:19 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/26 17:55:31 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

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
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_is_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_pipe_before_exit(t_cmd *cmd)
{
	t_node	*start;
	int		i;

	i = 0;
	start = cmd->cmd_start;
	while (start && i++ < cmd->size)
	{
		if (start->type == PIPE)
			return (1);
		start = start->next;
	}
	return (0);
}

int	ft_set_exit_code(char *str)
{
	int	exit_code;

	exit_code = ft_atoi(str);
	if (exit_code >= 0)
		exit_code = exit_code % 256;
	else if (exit_code < 0)
	{
		while (exit_code < 0)
			exit_code += 256;
	}
	return (exit_code);
}

void	ft_exit_with_message(t_cmd *cmd_start)
{
	ft_putendl_fd("\033[38;5;31mexit\033[0m", 2);
	ft_exit_minishell(g_info.exit_code, &(cmd_start));
}
