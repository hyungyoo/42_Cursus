#include "../includes/minishell.h"

void	ft_del_list_one_node(t_cmd *cmd, t_node *node)
{
	cmd->cmd_start = NULL;
	free(node->str);
	free(node);
}

void	ft_del_list_last_node(t_cmd *cmd, t_node *node)
{
	(void)cmd;
	node->prev->next = NULL;
	free(node->str);
	free(node);
}

void	ft_del_list(t_cmd *cmd, t_node *node)
{
	int	size_node;

	size_node = cmd->size;
	if (size_node == 1)
		ft_del_list_one_node(cmd, node);
	else if (!(node->next) || size_node == 2)
		ft_del_list_last_node(cmd, node);
	else if (node->next)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		free(node->str);
		free(node);
	}
}

void	ft_reset_value(t_cmd *cmd, t_node **node)
{
	char	*tmp;
	t_node	*next_node;

	tmp = NULL;
	if (!node || !(*node) || !((*node)->next))
		return ;
	next_node = (*node)->next;
	tmp = (*node)->str;
	(*node)->str = ft_strdup(ft_getenv(g_info.envp, next_node->str));
	(*node)->type = ARG;
	(*node)->flag_nospace = next_node->flag_nospace;
	free(tmp);
	ft_del_list(cmd, next_node);
}

void	ft_reset_value_douq(t_cmd *cmd, t_node **node)
{
	char	*new_str;
	int		i;
	int		last;

	(void)cmd;
	i = 0;
	new_str = NULL;
	while (((*node)->str)[i])
	{
		while (((*node)->str)[last] && !(((*node)->str)[last] == ' ' || ((*node)->str)[last] == '$' || ((*node)->str)[last] == 39))
}

void	ft_expension(t_cmd **cmd)
{
	t_node	*node;

	node = (*cmd)->cmd_start;
	while (node)
	{
		if (node->type == DOLR && node->flag_nospace == 1 && node->next && ft_strcmp(node->next->str, "?"))
			ft_reset_value(*cmd, &node);
		else if (node->type == DOUQ)
			ft_reset_value_douq(*cmd, &node);
		if (node->next)
			node = node->next;
		else
			return ;
	}
}
