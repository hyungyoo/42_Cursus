/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:45:50 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/29 16:04:30 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_left_fd_pipe(t_node **node, t_fd_pipe *fd, int flag)
{
	if (!(*node)->next || ((*node)->next && (*node)->next->type == PIPE))
	{
		ft_putstr_fd("minishell: syntax error ", 2);
		ft_putstr_fd("near unexpected token 'newline'\n", 2);
		return (0);
	}
	(*node) = (*node)->next;
	if (check_redir(*node))
	{
		ft_putstr_fd("minisehll: syntax error near unexpected token `<'\n", 2);
		return (0);
	}
	if (check_dleft((*node)->prev) == LEFT)
	{
		fd->fd_in = open((*node)->str, O_RDONLY, 0644);
		if (fd->fd_in == -1)
		{
			ft_error_message_left((*node)->str);
			return (0);
		}
		if (!flag)
			return (0);
		dup2(fd->fd_in, 0);
	}
	return (1);
}

void	heredoc_parent_pipe(t_fd_pipe *fd, int status)
{
	close(fd->fd_heredoc_pipe[1]);
	dup2(fd->fd_heredoc_pipe[0], 0);
	waitpid(g_info.pid_child, &status, 0);
	g_info.pid_child = 0;
	g_info.exit_code = WEXITSTATUS(status);
}

void	heredoc_child_pipe(t_fd_pipe *fd, t_cmd *cmd, t_node **node)
{
	char	*line;

	close(fd->fd_heredoc_pipe[0]);
	dup2(fd->fd_heredoc_pipe[1], 1);
	ft_putstr_fd("pipe heredoc> ", 2);
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strcmp(line, (*node)->str))
		{
			free(line);
			break ;
		}
		else
			ft_putstr_fd("pipe heredoc> ", 2);
		ft_putstr_fd(line, 1);
		ft_putstr_fd("\n", 1);
		free(line);
	}
	ft_exit_minishell(0, &cmd);
}

void	heredoc(t_cmd *cmd, t_node *node)
{
	char	*line;

	(void)cmd;
	ft_putstr_fd("pipe heredoc> ", 2);
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strcmp(line, (node)->str))
		{
			free(line);
			break ;
		}
		else
			ft_putstr_fd("pipe heredoc> ", 2);
		free(line);
	}
}

int	ft_dleft_fd_pipe(t_node **node, t_fd_pipe *fd, t_cmd *cmd, int flag)
{
	int	status;

	status = 0;
	if (!check_dleft_error(node))
		return (0);
	if (check_dleft((*node)->prev) == DLEFT && flag)
	{
		pipe(fd->fd_heredoc_pipe);
		g_info.pid_child = fork();
		if (g_info.pid_child > 0)
			heredoc_parent_pipe(fd, status);
		else if (g_info.pid_child == 0)
			heredoc_child_pipe(fd, cmd, node);
	}
	if (check_dleft((*node)->prev) == DLEFT && !flag)
	{
		heredoc(cmd, *node);
		ft_exit_minishell(g_info.exit_code, &cmd);
	}
	else if (check_dleft((*node)->prev) != DLEFT)
		heredoc(cmd, *node);
	return (1);
}
