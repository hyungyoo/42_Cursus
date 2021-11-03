#include "../includes/minishell.h"

void	ft_move_to_last(t_node **node)
{
	if (!node || !*node || (*node)->type == PIPE)
		return ;
	while ((*node))
	{
		if ((*node)->type == PIPE)
		{
				(*node) = (*node)->prev;
				return ;
		}
		if ((*node)->next)
			(*node) = (*node)->next;
		else
			return ;
	}
}

void	execute_cmds_pipe(t_node **node, t_cmd *cmd)
{
	if ((*node)->type == BUILTIN_CMD)
		ft_built_in_pipe(node, cmd);
	else if ((*node)->type == CMD)
		ft_execmd(*node, cmd);
}

void	ft_error_message_left(char *str)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": No such file or directory", 2);
	g_info.exit_code = 1;
}

int	ft_left_fd(t_node **node, t_fd *fd)
{
	if (!(*node)->next)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token 'newline'\n", 2);
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

int	ft_dleft_fd(t_node **node, t_fd *fd, t_cmd *cmd)
{
	char *line;
	int	status;

	pipe(fd->fd_heredoc_pipe);
	g_info.pid_child = fork();
	if (!(*node)->next)
	{
		ft_putstr_fd("minishell: parse error near '\n'\n", 2);
		return (0);
	}
	(*node) = (*node)->next;
	if (g_info.pid_child > 0)
	{
		close(fd->fd_heredoc_pipe[1]);
		dup2(fd->fd_heredoc_pipe[0], 0);
		waitpid(g_info.pid_child, &status, 0);
		g_info.pid_child = 0;
		g_info.exit_code = WEXITSTATUS(status);
	}
	else if (g_info.pid_child == 0)
	{
		close(fd->fd_heredoc_pipe[0]);
		dup2(fd->fd_heredoc_pipe[1], 1);
		while (get_next_line(0, &line) > 0)
		{
			if (!ft_strcmp(line, (*node)->str))
			{
				free(line);
				break ;
			}
			ft_putstr_fd(line, 1);
			ft_putstr_fd("\n", 1);
			free(line);
		}
		ft_exit_minishell(0, &cmd);
	}
	return (1);
}

int	ft_right_fd(t_node **node, t_fd *fd)
{
	if (!(*node)->next)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token 'newline'\n", 2);
		return (0);
	}
	(*node) = (*node)->next;
	fd->fd_out = open((*node)->str, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd->fd_out == -1)
		return (0);
	dup2(fd->fd_out, 1);
	return (1);
}

int	ft_dright_fd(t_node **node, t_fd *fd)
{
	if (!(*node)->next)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token 'newline'\n", 2);
		return (0);
	}
	(*node) = (*node)->next;
	fd->fd_out = open((*node)->str, O_CREAT | O_APPEND | O_RDWR, 0644);
	if (fd->fd_out == -1)
		return (0);
	dup2(fd->fd_out, 1);
	return (1);
}

int	ft_fd_checker(t_node *node, t_fd *fd, t_cmd *cmd)
{
	t_node	*tmp;
	int		flag_exit;

	flag_exit = 1;
	tmp = node->prev;
	while (node != tmp && node->type != PIPE)
	{
		if (!strcmp(node->str, "<"))
			flag_exit = ft_left_fd(&node, fd);
		else if (!strcmp(node->str, "<<"))
			flag_exit = ft_dleft_fd(&node, fd, cmd);
		else if (!strcmp(node->str, ">"))
			flag_exit = ft_right_fd(&node, fd);
		else if (!strcmp(node->str, ">>"))
			flag_exit = ft_dright_fd(&node, fd);
		if (!flag_exit)
			return (0);
		if (node->next)
			node = node->next;
		else
			break ;
	}
	return (1);
}

void	ft_execve_cmd(t_node **node, t_cmd *cmd)
{
	int	status;

	g_info.pid_child = fork();
	if (g_info.pid_child == 0)
		ft_execmd(*node, cmd);
	else if (g_info.pid_child > 0)
	{
		waitpid(g_info.pid_child, &status, 0);
		g_info.pid_child = 0;
		g_info.exit_code = WEXITSTATUS(status);
	}
}

void	ft_set_fd(t_fd *fd)
{
	fd->fd_std_in = dup(0);
	fd->fd_std_out = dup(1);
	fd->fd_in  = -1;
	fd->fd_out = -1;
}

void	ft_close_fd(t_fd *fd)
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


void	execute_cmds(t_node **node, t_cmd *cmd)
{
	t_fd	fd;
	t_node	*tmp;

	tmp = (*node)->prev;
	ft_set_fd(&fd);
	if (ft_fd_checker(*node, &fd, cmd))
	{
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
			ft_execve_cmd(node, cmd);
	}
	ft_close_fd(&fd);
	ft_move_to_last(node);
	ft_update_last_env((*node)->str);
}

int	count_pipe(t_node *node)
{
	int		count_pipe;
	t_node	*tmp;

	count_pipe = 0;
	tmp = node->prev;
	while (node && node != tmp)
	{
		if (node->type == PIPE)
			count_pipe++;
		node = node->next;
	}
	return (count_pipe);
}

void	ft_error_message_exec(void)
{
	ft_putstr_fd("minishell: syntax error near unexpected |\n", 2);
}

void	ft_exec_pipe(t_node *node, t_cmd *cmd)
{
	if (!node)
	 	return ;
	//init_befor_exec(node);
	while (node)
	{
		execute_cmds_pipe(&node, cmd); //fork for built in aussi
		if (node->next && node->type != PIPE)
				node = node->next;
		if (node->next)
			node = node->next;
		else
			break ;
	}
}

int	ft_check_pipe_error(t_node *node)
{
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

/* 
 * to do:
 * 1 execuve함수와 일반 빌트인함수에서 나오는 다이렉션 무시하고 할수있도록 해야함 즉 12인 arg만 읽도록 아니면 넘기도록
 */

void	ft_exec(t_cmd *cmd)
{
	t_node	*node;

	node = cmd->cmd_start;
	if (!node)
		return ;
	get_type_dir(node);
	//printf("%d pipe = %d == cmd\n", count_pipe(node), count_cmd(node));
	// echo str | < file 또한 에러로읽힌다. cmd가 아니기때문, 아니면, 한바퀴돌면서
	// 파이프다음에 이것들중에 하나라도 없으면 에러?
	if (!ft_check_pipe_error(node))
		ft_error_message_exec();
	else if (count_pipe(node) == 0)
		execute_cmds(&node, cmd);
	/*
	else if (count_pipe(node) >= 1)
		ft_exec_pipe(node);	// fork all
	*/
}
