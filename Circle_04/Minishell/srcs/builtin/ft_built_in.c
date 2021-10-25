/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:31:21 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/22 17:48:15 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//void	ft_pass_arg(t_node **cmd);
//to do:
//	1. passe arg until next pipe ou redir
//	2. and check il y a arg?
static void	ft_error_message(t_node **cmd)
{
	ft_putstr("minishell: ");
	while ((*cmd) && (*cmd)->flag_nospace == 1)
	{
		ft_putstr((*cmd)->str);
		if ((*cmd)->next)
			(*cmd) = (*cmd)->next;
	}
	ft_putstr((*cmd)->str);
	ft_putstr(": command not found\n");
	g_info.exit_code = 127;
}

void	ft_built_in(t_node	**cmd)
{
	if ((*cmd)->flag_nospace == 1)
		ft_error_message(cmd);
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
		ft_exit_builtin(cmd);
	if ((*cmd)->next)
		if ((*cmd)->next->type != PIPE)
			while ((*cmd)->next->type == PIPE && (*cmd)->next)
				(*cmd) = (*cmd)->next;
}
