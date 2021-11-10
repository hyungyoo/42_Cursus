#include "../includes/minishell.h"

///////////////함수에서 leak이 날 것만 같은데... 확인 좀 해줄 수 있겠니.../////////
char	*replace_expansion(char *exp, char *rest)
{
	char	*tmp;
	char	*tmp2;

	if (ft_getenv(g_info.envp, exp))
		tmp = ft_strjoin(ft_getenv(g_info.envp, exp), rest);
	else
	{
		tmp2 = ft_strdup("");
		tmp = ft_strjoin(tmp2, rest);
		free(tmp2);
	}
	return (tmp);
}
//////////////////////////////////////////////////////////////////////

char	*replace_str(char *str, int *index)
{
	char	*exp;
	char	*rest;
	char	*tmp;
	int		i;

	i = *index;
	// printf("i is ? %d\n", i);
	while (str[i] && ft_is_letter(str[i]))
		i++;
	exp = ft_substr(str, *index, i - *index);
	rest = ft_substr(str, i, ft_strlen(str));
	tmp = replace_expansion(exp, rest);
	free(exp);
	free(rest);
	*index = i;
	//printf("index:%d\n", *index);
	// printf("exp:%s\n", exp);
	// printf("rest:%s\n", rest);
	return (tmp);
}

void	replace_expansion_in_dquote(char **str)
{
	char	*tmp;
	char	*string;
	int		i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '$' && (*str)[i + 1] == '\0')
		{
			// printf("here\n");
			*str = ft_strcpy(*str, "$");
		}
		else if ((*str)[i] == '$')
		{
			string = ft_substr(*str, 0, i);
			// printf("string: |%s|\n", string);
			// printf("i: %c", (*str)[i]);
			tmp = replace_str(*str, &i);
			//printf("tmp: |%s|\n", tmp);
			free(*str);
			*str = ft_strjoin(string, tmp);
			//printf("str: |%s|\n", *str);
			free(string);
			free(tmp);
			//printf("i== %d\n", i);
		}
		i++;
	}
}

char	*replace_env(char *exp)
{
	char *tmp;

	if (ft_getenv(g_info.envp, exp))
		tmp = ft_strdup(ft_getenv(g_info.envp, exp));
	else
		tmp = ft_strdup("");
	return (tmp);
}

char	*replace_argstr(char *str)
{
	char	*exp;
	char	*tmp;
	int		i;

	i = 0;
	while (str[i] && ft_is_letter(str[i]))
		i++;
	exp = ft_substr(str, 0, i);
	// printf("exp:%s\n", exp);
	tmp = replace_env(exp);
	free(exp);
	return (tmp);
}

void	ft_delnode(t_node **node)
{
	t_node *tmp;
	t_node *node_to_free;

	if (!(*node))
		return ;
	node_to_free = *node;
	if ((*node)->next)
	{
		tmp = (*node)->prev->next;
		(*node)->prev->next = (*node)->next;
		(*node)->next->prev = tmp;
		free(node_to_free->str);
		//free(node_to_free);
		// free(*node);
	}
	else
	{
		(*node)->prev->next = NULL;
		free(node_to_free->str);
		free(node_to_free);
		// free((*node)->str);
		// free(*node);
	}
}

void	replace_expansion_as_arg(char **str, t_node **node)
{
	char	*tmp;
	int		i;

	i = 0;
	// printf("(*node)->str: %s\n", (*node)->str);
	// printf("(*node)->next->str: %s\n", (*node)->next->str);

	while ((*str)[i])
	{
		if ((*str)[i] == '$')
		{
			tmp = replace_argstr((*node)->next->str);
			// printf("tmp: |%s|\n", tmp);
			*str = ft_strdup(tmp);
		}
		if (!ft_strcmp((*str), ""))
			break ;
		else
			i++;
	}
	(*node)->flag_nospace = 0;
	ft_delnode(&(*node)->next);
}

void	ft_expension(t_cmd **cmd)
{
	t_node *node;

	node = (*cmd)->cmd_start;
	while (node)
	{
		/* ignore when cmd is echo */
		if ((node->type == BUILTIN_CMD && !ft_strcmp(node->str, "echo")))
			break ;
		/* when "$PWD" is in quote */
		if ((ft_strchr((node->str), '$') && node->type == DOUQ && node->type != SINQ))
		{
			//printf("expansion case double quote\n");
			replace_expansion_in_dquote(&node->str);
		}
		/* when $PWD is out of quote */
		else if (node->type == DOLR && node->next && node->next->type == ARG)
		{
			//printf("expansion case arg\n");
			replace_expansion_as_arg(&node->str, &(node));
			break ;
		}
		
		if (node->next)
			node = node->next;
		else
			break;
	}	
}
