/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:00:19 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/06 20:14:00 by hyungyoo         ###   ########.fr       */
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
		if (i == 0 && str[i] == '-' && i++)
			continue ;
		else if (!ft_is_digit(str[i]))
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
	ft_putendl_fd("\033[38;5;31mminishell exit \033[0m", 2);
	ft_exit_minishell(g_info.exit_code, &(cmd_start));
}

void	ft_error_message_string_arg(t_node *node, t_cmd *cmd)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd((node)->str, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	g_info.exit_code = 255;
	ft_exit_with_message(cmd);
}

void	ft_exit_builtin(t_node **cmd, t_cmd *cmd_start)
{
	g_info.exit_code = 0;
	if (ft_check_pipe_before_exit(cmd_start))
		return ;
	if (!((*cmd)->next))
		ft_exit_with_message(cmd_start);
	while ((*cmd) && (*cmd)->type != ARG)
		(*cmd) = (*cmd)->next;
	if (!ft_check_num_exit((*cmd)->str))
		ft_error_message_string_arg((*cmd), cmd_start);
	else if (ft_check_num_exit((*cmd)->str))
	{
		if ((*cmd)->next)
		{
			ft_putendl_fd("\033[38;5;31mminishell exit \033[0m", 2);
			ft_putstr_fd("minishell : exit: too many arguments\n", 2);
			g_info.exit_code = 1;
			return ;
		}
		g_info.exit_code = ft_set_exit_code((*cmd)->str);
		ft_exit_with_message(cmd_start);
	}
}
