/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:45:50 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/12/02 18:25:37 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	check_cmd(t_node *node)
{
	while (node && node->type != PIPE)
	{
		if (node->type == CMD || node->type == BUILTIN_CMD)
			return (1);
		if (node->next)
			node = node->next;
		else
			break ;
	}
	return (0);
}

int	check_heredoc_fd(t_node **node)
{
	if (!(check_dleft_next_cmd(*node) == DLEFT
			&& check_dleft_file(*node) == TRUE))
		return (1);
	return (0);
}

int	check_only_heredoc(t_node *node)
{
	while (node && node->type != PIPE)
	{
		if (node->type == DLEFT)
			return (1);
		if (node->next)
			node = node->next;
		else
			break ;
	}
	return (0);
}

int	next_cmd_heredoc(t_node *node)
{
	if (!check_next_pipe_node(&node))
		return (0);
	while (node)
	{
		if (node->type == DLEFT)
			return (1);
		if (node->next)
			node = node->next;
		else
			break ;
	}
	return (0);
}

void	execute_pipe_child(t_node **node, t_cmd *cmd, t_fd_pipe *fd)
{
	close(fd->pipe_fd[0]);
	dup2(fd->pipe_fd[1], 1);
	execute_cmds_pipe(node, cmd, fd);
	close(fd->pipe_fd[1]);
	ft_exit_minishell(g_info.exit_code, &cmd);
}
