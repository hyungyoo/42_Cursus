/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:31:21 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/18 12:53:26 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_error_message_builtin(t_node **cmd)
{
	ft_putstr_fd("minishell: ", 2);
	while ((*cmd) && (*cmd)->flag_nospace == 1)
	{
		ft_putstr_fd((*cmd)->str, 2);
		if ((*cmd)->next)
			(*cmd) = (*cmd)->next;
	}
	ft_putstr_fd((*cmd)->str, 2);
	ft_putstr_fd(": command not found\n", 2);
	g_info.exit_code = 127;
}

void	ft_built_in_pipe(t_node	**cmd, t_cmd *cmd_start)
{
	if ((*cmd)->flag_nospace == 1 && !ft_not_type(*cmd))
		ft_error_message_builtin(cmd);
	else if (!ft_strcmp((*cmd)->str, "echo"))
		ft_echo(cmd);
	else if (!ft_strcmp((*cmd)->str, "pwd"))
		ft_pwd(cmd);
	else if (!ft_strcmp((*cmd)->str, "cd"))
		ft_cd(cmd);
	else if (!ft_strcmp((*cmd)->str, "export"))
		ft_export(cmd);
	else if (!ft_strcmp((*cmd)->str, "unset"))
		ft_unset(cmd);
	else if (!ft_strcmp((*cmd)->str, "env"))
		ft_env(cmd);
	else if (!ft_strcmp((*cmd)->str, "exit"))
		ft_exit_builtin(cmd, cmd_start);
	ft_exit_minishell(g_info.exit_code, &(cmd_start));
}

void	ft_built_in(t_node	**cmd, t_cmd *cmd_start)
{
	if ((*cmd)->flag_nospace == 1 && !ft_not_type(*cmd))
		ft_error_message_builtin(cmd);
	else if (!ft_strcmp((*cmd)->str, "echo"))
		ft_echo(cmd);
	else if (!ft_strcmp((*cmd)->str, "pwd"))
		ft_pwd(cmd);
	else if (!ft_strcmp((*cmd)->str, "cd"))
		ft_cd(cmd);
	else if (!ft_strcmp((*cmd)->str, "export"))
		ft_export(cmd);
	else if (!ft_strcmp((*cmd)->str, "unset"))
		ft_unset(cmd);
	else if (!ft_strcmp((*cmd)->str, "env"))
		ft_env(cmd);
	else if (!ft_strcmp((*cmd)->str, "exit"))
		ft_exit_builtin(cmd, (cmd_start));
}
