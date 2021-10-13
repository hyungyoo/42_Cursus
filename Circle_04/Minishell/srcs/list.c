#include "../includes/minishell.h"

t_cmd	*init_cmd(void)
{	
	t_cmd *cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd)); /* dont forget : free ft needed */
	if (!cmd)
		return (NULL);
	cmd->size = 0;
	cmd->cmd_node = NULL;
	return (cmd);
}

void	insert_node(t_cmd **cmd, int type, char *str)
{
	t_node *new;
	t_node *tmp;

	new = (t_node *)malloc(sizeof(t_node)); /* dont forget : free ft needed */
	if (!new)
		return ;
	new->next = NULL;
	new->str = str;
	new->type = type;
	tmp = (*cmd)->cmd_node;
	if (tmp == NULL)
		(*cmd)->cmd_node = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	(*cmd)->size++;
}

void	free_list(t_cmd **cmd)
{
	t_node	*tmp;

	while ((*cmd)->cmd_node)
	{
		tmp = (*cmd)->cmd_node->next;
		free((*cmd)->cmd_node->str);
		(*cmd)->cmd_node->str = NULL;
		free((*cmd)->cmd_node);
		(*cmd)->cmd_node = NULL;
		(*cmd)->cmd_node = tmp;
	}
	free(*cmd);
}

/* tmp */

int		get_listsize(t_node **node)
{
	t_node	*tmp;
	int		size;

	tmp = *node;
	size = 0;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

void	print_cmdline(t_cmd **cmd)
{
	t_node *tmp;

	if (!cmd)
		return ;
	tmp = (*cmd)->cmd_node;
	while (tmp)
	{
		printf("type: %d\n", tmp->type);
		printf("str: %s\n", tmp->str);
		tmp = tmp->next;
	}
}

