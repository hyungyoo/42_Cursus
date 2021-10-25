/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:00:19 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/22 19:03:22 by hyungyoo         ###   ########.fr       */
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

void	ft_exit_builtin(t_node **cmd)
{
	if (!cmd || !*cmd)
		return ;
	if (!ft_strcmp((*cmd)->str, "exit"))
	{
		ft_putendl_fd("\033[38;5;31mminishell exit \033[0m", 1);
		ft_free_cmd(*cmd);
		ft_exit(1);
	}
}
