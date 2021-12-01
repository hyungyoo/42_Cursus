/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:45:50 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/12/02 00:13:12 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	execute_pipe(t_node **node, t_cmd *cmd, int i)
{
	int			status;
	t_fd_pipe	fd;

	pipe(fd.pipe_fd);
	g_info.pid_pipe_child[i] = fork();
	if (g_info.pid_pipe_child[i] == 0)
		execute_pipe_child(node, cmd, &fd);
	else if (g_info.pid_pipe_child[i] > 0)
	{
		close(fd.pipe_fd[1]);
		if (!next_cmd_heredoc(*node))
			dup2(fd.pipe_fd[0], 0);
		if (check_only_heredoc(*node))
		{
			waitpid(g_info.pid_pipe_child[i], NULL, 0);
			g_info.pid_pipe_child[i] = 0;
		}
		close(fd.pipe_fd[0]);
		g_info.pid_child = 0;
		g_info.exit_code = WEXITSTATUS(status);
		ft_move_to_last(node);
		ft_update_last_env((*node)->str);
	}
}

void	wait_pid(int pipe_count)
{
	int	i;

	i = 0;
	while (i < pipe_count)
	{
		if (g_info.pid_pipe_child[i] != 0)
			waitpid(g_info.pid_pipe_child[i], NULL, 0);
		i++;
	}
	waitpid(g_info.pid_child, NULL, 0);
	i = 0;
	while (i < pipe_count)
		g_info.pid_pipe_child[i++] = 0;
	g_info.pid_child = 0;
}

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
