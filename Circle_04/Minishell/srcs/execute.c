#include "../includes/minishell.h"

void	ft_move_to_pipe(t_node **node)
{
	if (!node || !*node || (*node)->type == PIPE)
		return ;
	while ((*node))
	{
		if ((*node)->type == PIPE)
				return ;
		if ((*node)->next)
			(*node) = (*node)->next;
		else
			return ;
	}
}

void	execute_cmds_pipe(t_node **node)
{
	if ((*node)->type == BUILTIN_CMD)
		ft_built_in_pipe(node);
	else if ((*node)->type == CMD)
		ft_execmd(*node);
}

void	execute_cmds(t_node **node)
{
	int	status;

	if ((*node)->type == BUILTIN_CMD)
		ft_built_in(node);
	else if ((*node)->type == CMD)
	{
		g_info.pid_child = fork();
		if (g_info.pid_child == 0)
			ft_execmd(*node);
		else if (g_info.pid_child > 0)
		{
			waitpid(g_info.pid_child, &status, 0);
			g_info.pid_child = 0;
			g_info.exit_code = WEXITSTATUS(status);
		}
	}
	// 있어야할까? 이게?
	//ft_move_to_pipe(node);
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

/*
int	count_cmd(t_node *node)
{
	int		count_cmd;
	t_node	*tmp;

	count_cmd = 0;
	tmp = node->prev;
	while (node && node != tmp)
	{
		if (node->type == BUILTIN_CMD || node->type == CMD)
			count_cmd++;
		node = node->next;
	}
	return (count_cmd);
}
*/
void	ft_error_message_exec(void)
{
	ft_putstr_fd("minishell: syntax error near unexpected |\n", 2);
}


void	ft_exec_builtin(t_node **node)
{
	ft_built_in(node);
	ft_exit_minishell(0, &(g_info.cmd));
}

void	ft_exec_multi_pipe(t_node *node)
{
	printf("for multi pipe\n");
	(void)node;

	//////////// set fd for < << > >> ////////
	// t_fd_set	fd_set;
	// ft_init_fd_set(&fd_set);
	// if (ft_left_redirect(node, fd_set))
		//dup(fd_set.fd_in, STDIN);
	// if (ft_left_redirect(node, fd_set))
		//dup(fd_set.fd_out, STDOUT);
	///////////////////////////////////////////
	/*
	   if (  fd_in of file for < or <<)
			exec_for_<
	   while (node.. etc, i < ft_num_pipe(node))
	   {
			execute_cmd_with_pipe(node)
			// to do:
			//	pipe(pipe_fd);
			// 	if (pid == 0)
			//	{
			//		close(pipe_fd[0]);
			//		dup2(pipe_fd[1], STDOUT);
			//		execute_cmd(node);
			//		free_all_for_fork_process
			//		exit();
			//	}
			//	else if (pid > 0)
			//	{
			//		close(pipe_fd[1]);
			//		dup2(pipe_fd[0], STDIN);
			//		wait
			//
	   		//	}
		}
		execute_last(node)
		{
			fork --> execute_cmd
		}

	*/


	///////////////////////////////////////
	// ft_reset_fd_set(&fd_set);
	/*

	int   ft_left_redirect and right(node, fd_set)
	   {
	   		if (ft_find_left(node, fd_set))
				return (1);
	   		if (ft_find_dleft(node, fd_set))
				return (1);
	   		if (ft_find_right(node, fd_set))
				return (1);
	   		if (ft_find_drignt(node, fd_set))
				return (1);
			return (0);
		}

	 */
}

void	ft_exec_pipe(t_node *node)
{
	if (!node)
	 	return ;
	//init_befor_exec(node);
	while (node)
	{
		execute_cmds_pipe(&node); //fork for built in aussi
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

void	ft_exec(t_node *node)
{
	if (!node)
		return ;
	get_type_dir(node);
	//printf("%d pipe = %d == cmd\n", count_pipe(node), count_cmd(node));
	// echo str | < file 또한 에러로읽힌다. cmd가 아니기때문, 아니면, 한바퀴돌면서
	// 파이프다음에 이것들중에 하나라도 없으면 에러?
	if (!ft_check_pipe_error(node))
		ft_error_message_exec();
	else if (count_pipe(node) == 0)
		execute_cmds(&node);
	/*
	else if (count_pipe(node) >= 1)
		ft_exec_pipe(node);	// fork all
	*/
}
