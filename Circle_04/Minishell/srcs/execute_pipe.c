#include "../includes/minishell.h"

int	ft_left_fd_pipe(t_node **node, t_fd_pipe *fd)
{
	if (!(*node)->next || (*node)->next->type == PIPE)
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
	dup2(fd->fd_in, 0);
	return (1);
}

void	heredoc_parent_pipe(t_fd_pipe *fd, int status)
{
	close(fd->fd_heredoc_pipe[1]);
	dup2(fd->fd_heredoc_pipe[0], 0);                /////////////////////////////////////
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

int	ft_dleft_fd_pipe(t_node **node, t_fd_pipe *fd, t_cmd *cmd)
{
	int	status;

	status = 0;
	pipe(fd->fd_heredoc_pipe);
	g_info.pid_child = fork();
	if (!(*node)->next || (*node)->next->type == PIPE)
	{
		ft_putstr_fd("minishell: parse error near '\n'\n", 2);
		return (0);
	}
	(*node) = (*node)->next;
	if (g_info.pid_child > 0)
		heredoc_parent_pipe(fd, status);
	else if (g_info.pid_child == 0)
		heredoc_child_pipe(fd, cmd, node);
	return (1);
}

int	ft_right_fd_pipe(t_node **node, t_fd_pipe *fd)
{
	if (!(*node)->next || (*node)->next->type == PIPE)
	{
		ft_putstr_fd("minishell: syntax error ", 2);
		ft_putstr_fd("near unexpected token 'newline'\n", 2);
		return (0);
	}
	(*node) = (*node)->next;
	fd->fd_out = open((*node)->str, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd->fd_out == -1)
		return (0);
	dup2(fd->fd_out, 1);
	return (1);
}

int	ft_dright_fd_pipe(t_node **node, t_fd_pipe *fd)
{
	if (!(*node)->next || (*node)->next->type == PIPE)
	{
		ft_putstr_fd("minishell: syntax error ", 2);
		ft_putstr_fd("near unexpected token 'newline'\n", 2);
		return (0);
	}
	(*node) = (*node)->next;
	fd->fd_out = open((*node)->str, O_CREAT | O_APPEND | O_RDWR, 0644);
	if (fd->fd_out == -1)
		return (0);
	dup2(fd->fd_out, 1);
	return (1);
}

int	ft_fd_checker_pipe(t_node *node, t_fd_pipe *fd, t_cmd *cmd)
{
	t_node	*tmp;
	int		flag_exit;

	flag_exit = 1;
	tmp = node->prev;
	while (node != tmp && node->type != PIPE)
	{
		if (node->str && !strcmp(node->str, "<"))
			flag_exit = ft_left_fd_pipe(&node, fd);
		else if (node->str && !strcmp(node->str, "<<"))
			flag_exit = ft_dleft_fd_pipe(&node, fd, cmd);
		else if (node->str && !strcmp(node->str, ">"))
			flag_exit = ft_right_fd_pipe(&node, fd);
		else if (node->str && !strcmp(node->str, ">>"))
			flag_exit = ft_dright_fd_pipe(&node, fd);
		if (!flag_exit)
			return (0);
		if (node->next)
			node = node->next;
		else
			break ;
	}
	return (1);
}

void	ft_set_fd_pipe(t_fd_pipe *fd)
{
	fd->fd_std_in = dup(0);
	fd->fd_std_out = dup(1);
	fd->fd_in = -1;
	fd->fd_out = -1;
}

void	ft_close_fd_pipe(t_fd_pipe *fd)
{
	dup2(fd->fd_std_in, 0);
	dup2(fd->fd_std_out, 1);
	if (fd->fd_in != -1)
		close(fd->fd_in);
	if (fd->fd_out != -1)
		close(fd->fd_out);
	close(fd->fd_std_in);
	close(fd->fd_std_out);
}

void	execute_cmds_pipe(t_node **node, t_cmd *cmd)
{
	t_node	*tmp;
	t_fd_pipe	fd;

	ft_set_fd_pipe(&fd);
	tmp = (*node)->prev;
	if (ft_fd_checker_pipe(*node, &fd, cmd)){
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
	ft_close_fd_pipe(&fd);
}

void    execute_pipe(t_node **node, t_cmd *cmd)
{
	int	status;
    int pipe_fd[2];

    pipe(pipe_fd);
	g_info.pid_child = fork();
	if (g_info.pid_child == 0)
    {
        close(pipe_fd[0]);
        dup2(pipe_fd[1], 1);
		execute_cmds_pipe(node, cmd);
        ft_exit_minishell(g_info.exit_code, &cmd);
    }
	else if (g_info.pid_child > 0)
	{
        close(pipe_fd[1]);
        dup2(pipe_fd[0], 0);
		waitpid(g_info.pid_child, &status, 0);
		g_info.pid_child = 0;
		g_info.exit_code = WEXITSTATUS(status);
        ft_move_to_last(node);
        ft_update_last_env((*node)->str);
	}
}

void    ft_exec_pipe(t_node *node, t_cmd *cmd)
{
    t_node  *tmp;
    int     i;
    int     pipe_count;
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
            return ;
    }
	execute_cmds(&node, cmd);
	ft_close_fd(&fd);
}
