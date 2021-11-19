/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:41:57 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/19 17:11:32 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_check_pipe_error(t_node *node)
{
	if (!node || (node->type == PIPE))
		return (0);
	while (node)
	{
		if (node->type == PIPE)
		{
			if (!(node->next))
				return (0);
		}
		if (node->next)
			node = node->next;
		else
			break ;
	}
	return (1);
}

void	ft_exec(t_cmd *cmd)
{
	t_node	*node;

	node = cmd->cmd_start;
	if (!node)
		return ;
	get_type_dir(node, cmd);
	if (!ft_check_pipe_error(node))
		ft_error_message_exec();
	else if (!count_pipe(node))
		execute_cmds(&node, cmd);
	else if (count_pipe(node))
		ft_exec_pipe(node, cmd);
}
