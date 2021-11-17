#include "../includes/minishell.h"

void	execute_cmds_pipe(t_node **node, t_cmd *cmd)
{
	t_node	*tmp;

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

void    execute_pipe(t_node **node, t_cmd *cmd)
{
	int	status;
    t_fd_pipe   fd;

    pipe(fd.pipe_fd);
	g_info.pid_child = fork();
	if (g_info.pid_child == 0)
    {
        close(fd.pipe_fd[0]);
        dup2(fd.pipe_fd[1], 1);
		execute_cmds_pipe(node, cmd);
        ft_exit_minishell(g_info.exit_code, &cmd);
    }
	else if (g_info.pid_child > 0)
	{
        close(fd.pipe_fd[1]);
        // 있다면 0이 fd_file_out을 가르키면되지
        dup2(fd.pipe_fd[0], 0);
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
