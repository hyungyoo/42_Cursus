#include "../includes/minishell.h"

void	execute_cmds(t_node *node)
{
	if (node->type == BUILTIN_CMD)
		ft_built_in(&node);
	else if (node->type == CMD)
		ft_execmd(node);
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

void	ft_error_message_exec(void)
{
	ft_putstr("minishell: syntax error near unexpected |\n");
}

void	ft_exec_multi_pipe(t_node *node)
{
	printf("for multi pipe\n");
	(void)node;
}

void	ft_exec_one_pipe(t_node *node)
{
	// ft_check_path_exec(node);
	// ft_execmd_child(node);
	
	// ft_built_in(node);
	// all_free_function;
	// exit(0);
	printf("for one pipe\n");
	(void)node;
}

void	ft_exec(t_node *node)
{
	if (!node)
		return ;
	printf("%d pipe = %d == cmd\n", count_pipe(node), count_cmd(node));
	if (count_pipe(node) && (count_cmd(node) <= (count_pipe(node))))
		ft_error_message_exec();
	else if (count_pipe(node) == 0)
		execute_cmds(node);
	else if (count_pipe(node) == 1)
		ft_exec_one_pipe(node);	// fork deux exec
	else if (count_pipe(node) > 1)
		ft_exec_multi_pipe(node);	// fork all
}

/*
int	init_befor_exec(t_node *node)
{
	pipe count;
}

void	ft_exec(t_node *node)
{
	if (!node)
	 	return ;
	//init_befor_exec(node);
	while (node)
	{
		execute_cmds(node);
		if (node->next && node->type != PIPE)
				node = node->next;
		if (node->next)
			node = node->next;
		else
			break ;
	}
}
*/


