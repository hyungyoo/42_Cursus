#include "../includes/minishell.h"

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

int	ft_left_fd_pipe(t_node **node, t_fd_pipe *fd, int flag)
{
	if (!(*node)->next || ((*node)->next && (*node)->next->type == PIPE))
	{
		ft_putstr_fd("minishell: syntax error ", 2);
		ft_putstr_fd("near unexpected token 'newline'\n", 2);
		return (0);
	}
	(*node) = (*node)->next;
	fd->fd_in = open((*node)->str, O_RDONLY, 0644);
	if (fd->fd_in == -1)
	{
		ft_error_message_left((*node)->str);
		return (0);
	}
	if (!flag)
		return (0);
	dup2(fd->fd_in, 0);
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
	ft_putstr_fd("> ", 2);
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strcmp(line, (*node)->str))
		{
			free(line);
			break ;
		}
		else
			ft_putstr_fd("> ", 2);
		ft_putstr_fd(line, 1);
		ft_putstr_fd("\n", 1);
		free(line);
	}
	ft_exit_minishell(0, &cmd);
}

int	ft_dleft_fd_pipe(t_node **node, t_fd_pipe *fd, t_cmd *cmd, int flag)
{
	int	status;

	status = 0;
	pipe(fd->fd_heredoc_pipe);
	g_info.pid_child = fork();
	if (!(*node)->next || ((*node)->next && (*node)->next->type == PIPE))
	{
		ft_putstr_fd("minishell: parse error near '\n'\n", 2);
		return (0);
	}
	(*node) = (*node)->next;
	if (!flag)
		return (0);
	if (g_info.pid_child > 0)
		heredoc_parent_pipe(fd, status);
	else if (g_info.pid_child == 0)
		heredoc_child_pipe(fd, cmd, node);
	return (1);
}

int	ft_right_fd_pipe(t_node **node, t_fd_pipe *fd, int flag)
{
	if (!(*node)->next || ((*node)->next && (*node)->next->type == PIPE))
	{
		ft_putstr_fd("minishell: syntax error ", 2);
		ft_putstr_fd("near unexpected token 'newline'\n", 2);
		return (0);
	}
	(*node) = (*node)->next;
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

/*
 * 여기 다시보기 ///////////////////////////////////////////////
 */
void	ft_set_fd_pipe(t_fd_pipe *fd)
{
	fd->fd_std_in_pipe = dup(fd->pipe_fd[0]);
	fd->fd_std_out_pipe = dup(fd->pipe_fd[1]);
	fd->fd_std_in = dup(0);
	fd->fd_std_in = dup(1);
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
	close(fd->fd_std_in);
	close(fd->fd_std_out);
	close(fd->fd_std_in_pipe);
	close(fd->fd_std_out_pipe);
}
/*
   fd 
*/
void	execute_cmds_pipe(t_node **node, t_cmd *cmd, t_fd_pipe *fd)
{
	t_node	*tmp;

	ft_set_fd_pipe(fd);
	if (ft_fd_checker_pipe(*node, fd, cmd, check_cmd(*node)))
	{
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
	//ft_close_fd_pipe(fd);	\\\\\\\\\\\fd error 
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
			break ; /////////리턴이었음 그래도상관없을듯
	}
	execute_cmds(&node, cmd);
	ft_close_fd(&fd);
}
