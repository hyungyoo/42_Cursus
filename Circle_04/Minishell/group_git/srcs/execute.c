#include "../includes/minishell.h"

void	execute_cmds(t_node *node)
{
	printf("///////////////////////////////////%s == node in execute_cmds\n", node->str);
	if (node->type == BUILTIN_CMD)
	{
		ft_built_in(&node);
		printf("////////////////////////////////%s == exit node built in\n", node->str);
	}
	else if (node->type == CMD)
	{
		ft_execmd(node);
		printf("//////////////////////////////%s == exit node exec\n", node->str);
	}
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
		printf("/////////////////////////////////%d eme exit node in while == %s\n", i, node->str);
		if (node->next && node->type != PIPE)
				node = node->next;
		node = node->next;
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
