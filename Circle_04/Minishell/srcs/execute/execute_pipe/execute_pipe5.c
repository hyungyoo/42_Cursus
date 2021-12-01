/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:45:50 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/12/01 21:11:40 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_exec_pipe(t_node *node, t_cmd *cmd)
{
	t_node	*tmp;
	int		i;
	int		pipe_count;
	t_fd	fd;

	i = 0;
	ft_set_fd(&fd);
	pipe_count = count_pipe(node);
	tmp = node->prev;
	while (node != tmp && i < pipe_count)
	{
		execute_pipe(&node, cmd, i);
		if (node->next && node->next->type == PIPE)
		{
			i++;
			node = node->next;
		}
		if (node->next)
			node = node->next;
		else
			break ;
	}
	execute_cmds(&node, cmd);
	ft_close_fd(&fd);
	wait_pid(pipe_count);
}
