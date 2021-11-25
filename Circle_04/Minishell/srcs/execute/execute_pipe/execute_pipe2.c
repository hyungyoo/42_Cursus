/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:45:50 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/25 05:12:42 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_right_fd_pipe(t_node **node, t_fd_pipe *fd, int flag)
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
		ft_putstr_fd("minisehll: syntax error near unexpected token `>'\n", 2);
		return (0);
	}
	fd->fd_out = open((*node)->str, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd->fd_out == -1)
		return (0);
	if (flag)
		dup2(fd->fd_out, 1);
	else
		close(fd->fd_out);
	return (1);
}

int	ft_dright_fd_pipe(t_node **node, t_fd_pipe *fd, int flag)
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
		ft_putstr_fd("minisehll: syntax error near unexpected token `>>'\n", 2);
		return (0);
	}
	fd->fd_out = open((*node)->str, O_CREAT | O_APPEND | O_RDWR, 0644);
	if (fd->fd_out == -1)
		return (0);
	if (flag)
		dup2(fd->fd_out, 1);
	else
		close(fd->fd_out);
	return (1);
}

int	ft_fd_checker_pipe(t_node *node, t_fd_pipe *fd, t_cmd *cmd, int flag)
{
	t_node	*tmp;
	int		flag_exit;
	int		ret;

	flag_exit = 1;
	ret = 1;
	tmp = node->prev;
	while (node != tmp && node->type != PIPE)
	{
		if (node->str && !strcmp(node->str, "<"))
			flag_exit = ft_left_fd_pipe(&node, fd, flag);
		else if (node->str && !strcmp(node->str, "<<"))
			flag_exit = ft_dleft_fd_pipe(&node, fd, cmd, flag);
		else if (node->str && !strcmp(node->str, ">"))
			flag_exit = ft_right_fd_pipe(&node, fd, flag);
		else if (node->str && !strcmp(node->str, ">>"))
			flag_exit = ft_dright_fd_pipe(&node, fd, flag);
		if (!flag_exit)
			ret = 0;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	return (ret);
}

void	ft_set_fd_pipe(t_fd_pipe *fd)
{
	fd->fd_std_in_pipe = dup(fd->pipe_fd[0]);
	fd->fd_std_out_pipe = dup(fd->pipe_fd[1]);
	fd->fd_std_in = dup(0);
	fd->fd_std_out = dup(1);
	fd->fd_in = -1;
	fd->fd_out = -1;
}

void	ft_close_fd_pipe(t_fd_pipe *fd)
{
	dup2(fd->fd_std_in_pipe, fd->fd_std_in);
	dup2(fd->fd_std_out_pipe, fd->fd_std_out);
	if (fd->fd_in != -1)
		close(fd->fd_in);
	if (fd->fd_out != -1)
		close(fd->fd_out);
	//close(fd->fd_std_in);
	//close(fd->fd_std_out);
	//close(fd->fd_std_in_pipe);
	//close(fd->fd_std_out_pipe);
}

void	execute_cmds_pipe(t_node **node, t_cmd *cmd, t_fd_pipe *fd)
{
	t_node	*tmp;

	ft_set_fd_pipe(fd);
	if (ft_fd_checker_pipe(*node, fd, cmd, check_cmd(*node)))
	{
		ft_close_fd_pipe(fd);
		tmp = (*node)->prev;
		while ((*node) != tmp)
		{
			if ((*node)->type == CMD || (*node)->type == BUILTIN_CMD)
				break ;
			if ((*node)->next)
				(*node) = (*node)->next;
			else
				break ;
		}
		if ((*node)->type == BUILTIN_CMD)
			ft_built_in(node, cmd);
		else if ((*node)->type == CMD)
			ft_execmd(*node, cmd);
	}
}

int	check_next_pipe_node(t_node **node)
{
	while (*node)
	{
		if ((*node)->type == PIPE)
		{
			if ((*node)->next)
				(*node) = (*node)->next;
			return (TRUE);
		}
		if ((*node)->next)
			(*node) = (*node)->next;
		else
			break ;
	}
	return (FALSE);
}

int	check_dleft(t_node *node)
{
	int	flag_redir;

	flag_redir = node->type;
	if (node->next)
		node = node->next;
	while (node && node->type != PIPE)
	{
		if (node->type == LEFT || node->type == DLEFT)
			flag_redir = 0;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	return (flag_redir);
}

int	check_dleft_next_cmd(t_node *node)
{
	int	flag_redir;

	flag_redir = 0;
	if (!check_next_pipe_node(&node))
		return (0);
	while (node)
	{
		if (node->type == LEFT)
			flag_redir = LEFT;
		else if (node->type == DLEFT)
			flag_redir = DLEFT;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	return (flag_redir);
}

int	check_dleft_file(t_node *node)
{
	int	flag_file;

	flag_file = TRUE;
	while (node)
	{
		if (node->type == DLEFT)
		{
			if (node->next && node->next->type == FILE)
				flag_file = TRUE;
			else
				flag_file = FALSE;
		}
		if (node->next)
			node = node->next;
		else 
			break ;
	}
	return (flag_file);
}

void	execute_pipe(t_node **node, t_cmd *cmd)
{
	int			status;
	t_fd_pipe	fd;

	pipe(fd.pipe_fd);
	g_info.pid_child = fork();
	if (g_info.pid_child == 0)
	{
		close(fd.pipe_fd[0]);
		dup2(fd.pipe_fd[1], 1);
		execute_cmds_pipe(node, cmd, &fd);
		close(fd.pipe_fd[1]);
		ft_exit_minishell(g_info.exit_code, &cmd);
	}
	else if (g_info.pid_child > 0)
	{
		waitpid(g_info.pid_child, &status, 0);
		close(fd.pipe_fd[1]);
		if (!(check_dleft_next_cmd(*node) == DLEFT && check_dleft_file(*node) == TRUE))
			dup2(fd.pipe_fd[0], 0);
		close(fd.pipe_fd[0]);
		g_info.pid_child = 0;
		g_info.exit_code = WEXITSTATUS(status);
		ft_move_to_last(node);
		ft_update_last_env((*node)->str);
	}
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
		execute_pipe(&node, cmd);
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
}
