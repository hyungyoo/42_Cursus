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

void	ft_ajouter_char(char **new_str, char c)
{
	int		size;
	char	*tmp;
	char	*ret;
	int		i;

	i = 0;
	if (!*new_str)
	{
		(*new_str) = (char *)malloc(sizeof(char) * 2);
		if (!*new_str)
			return ;
		(*new_str)[i++] = c;
		(*new_str)[i] = '\0';
		return ;
	}
	size = ft_strlen(*new_str) + 1;
	ret = (char *)malloc(sizeof(char) * size + 1);
	if (!ret)
		return ;
	while ((*new_str)[i])
	{
		ret[i] = (*new_str)[i];
		i++;
	}
	ret[i++] = c;
	ret[i] = '\0';
	tmp = *new_str;
	*new_str = ret;
	free(tmp);
}

void	ft_ajouter_dolr(char **new_str, char *str, int *i)
{
	int	j;
	char	*tmp_key;
	int		size;

	(*i)++;
	j = *i;
	while (str[*i])
	{
		if (str[*i] == ' ' || str[*i] == '|' || str[*i] == 39 || str[*i] == '$')
			break ;
		(*i)++;
	}
	size = *i - j;

	////////////// key 만들기//////////
	tmp_key = (char *)malloc(sizeof(char) * size + 1);
	if (!tmp_key)
		return ;
	int	k;
	k = 0;
	while (k < size)
	{
		tmp_key[k++] = str[j++];
	}
	tmp_key[k] = '\0';

	////////////// key로 env값 찾기////////////////
	if (ft_getenv(g_info.envp, tmp_key))
		*new_str = ft_strjoin_free(*new_str, ft_getenv(g_info.envp, tmp_key));
	else
		*new_str = ft_strjoin_free(*new_str, "");
	free(tmp_key);
}

void	ft_ajouter_exit_code(char **new_str, int *i)
{
	char	*num;

	num = NULL;
	num = ft_itoa(g_info.exit_code);
	*new_str = ft_strjoin_free(*new_str, num);
	free(num);
	(*i) = (*i) + 2;
	
}

void	ft_reset_value_douq(t_cmd *cmd, t_node **node)
{
	char	*new_str;
	char	*tmp;
	int		i;

	(void)cmd;
	i = 0;
	new_str = NULL;
	tmp = (*node)->str;
	while (((*node)->str)[i])
	{
		if (((*node)->str)[i] == '$' && ((*node)->str)[i + 1] && ((*node)->str)[i + 1] && ((*node)->str)[i + 1] != '?'
			&& ((*node)->str)[i + 1] != ' ')
			ft_ajouter_dolr(&new_str, (*node)->str, &(i));
		else if (((*node)->str)[i] == '$' && ((*node)->str)[i + 1] && ((*node)->str)[i + 1] == '?')
			ft_ajouter_exit_code(&new_str, &(i));
		else //if (((*node)->str)[i] != '$')
			ft_ajouter_char(&new_str, (((*node)->str)[i++]));
	}
	(*node)->str = new_str;
	free(tmp);
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
