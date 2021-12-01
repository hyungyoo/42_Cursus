/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:45:50 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/12/01 18:03:38 by hyungyoo         ###   ########.fr       */
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

void	execute_pipe(t_node **node, t_cmd *cmd, int i)
{
	int			status;
	t_fd_pipe	fd;

	pipe(fd.pipe_fd);
	g_info.pid_pipe_child[i] = fork();
	if (g_info.pid_pipe_child[i] == 0)
	{
		close(fd.pipe_fd[0]);
		dup2(fd.pipe_fd[1], 1);
		execute_cmds_pipe(node, cmd, &fd);
		close(fd.pipe_fd[1]);
		ft_exit_minishell(g_info.exit_code, &cmd);
	}
	else if (g_info.pid_pipe_child[i] > 0)
	{
		close(fd.pipe_fd[1]);
		if (check_heredoc_fd(node))
			dup2(fd.pipe_fd[0], 0);
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
		waitpid(g_info.pid_pipe_child[i++], NULL, 0);
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
