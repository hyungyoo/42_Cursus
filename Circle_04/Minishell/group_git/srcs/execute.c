#include "../includes/minishell.h"

void	execute_cmds(t_node *node)
{
	if (node->type == BUILTIN_CMD)
		ft_built_in(&node);
	else if (node->type == CMD)
		ft_execmd(node);
}

void	init_befor_exec(t_node *node)
{
	t_node *tmp;

	tmp = node;
	g_info.fork_flag = 0;
	g_info.count_pipe = 0;
	while (tmp)
	{
		if (tmp->type == PIPE)
			g_info.count_pipe++;
		if (tmp->next)
			tmp = tmp->next;
		else
			break;
	}
}

void	ft_exec(t_node *node)
{
	int	i = 1;

	init_befor_exec(node);
	while (node)
	{

		//set_pipe
		// redirect_in
		//  redirect_out
		//	pipe_flag == 1;
		execute_cmds(node);
		if (node->next && node->type != PIPE)
				node = node->next;
		node = node->next;
		if (node)
		i++;
	}
	// if (g_info.fork_flag)
	// {
	// 	while (waitpid(-1, &status, 0) > 0)
	// 	{
	// 		printf("waiting\n");
	// 		if(WIFEXITED(status) == 0)
	// 			g_info.exit_code = WEXITSTATUS(status);
	// 	}
	// }
}
