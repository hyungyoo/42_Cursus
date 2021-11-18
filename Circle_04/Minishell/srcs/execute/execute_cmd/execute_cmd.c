/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:14:36 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/18 15:14:59 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	count_arg(t_node *node)
{
	int	size;

	size = 0;
	while (node && node->type != PIPE)
	{
		if (ft_not_type(node))
		{
			if (node->flag_nospace == 0)
				size++;
			else if (node->flag_nospace == 1)
			{
				if (node->next && !ft_not_type(node->next))
					size++;
			}
		}
		if (node->next)
			node = node->next;
		else
			break ;
	}
	return (size);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*ret;
	int		size_str;
	int		i;
	int		index;

	ret = NULL;
	if (!s1)
		ret = ft_strdup((s2));
	else
	{
		size_str = ft_strlen(s1) + ft_strlen(s2);
		ret = (char *)malloc(sizeof(char) + size_str + 1);
		if (!ret)
			return (NULL);
		index = 0;
		i = 0;
		while (s1[index])
			ret[i++] = s1[index++];
		index = 0;
		while (s2[index])
			ret[i++] = s2[index++];
		ret[i] = '\0';
		free(s1);
	}
	return (ret);
}

char	*ft_arg(t_node **node)
{
	char	*ret;

	ret = NULL;
	if (!node || !*node)
		return (NULL);
	while (*node && (*node)->flag_nospace == 1)
	{
		ret = ft_strjoin_free(ret, (*node)->str);
		if ((*node)->next)
			(*node) = (*node)->next;
	}
	if ((*node))
		ret = ft_strjoin_free(ret, (*node)->str);
	return (ret);
}

void	ft_set_path_arg(t_node **node, char ***path_arg, int *i)
{
	if ((*node)->flag_nospace == 1 && (*node)->next
		&& ft_not_type((*node)->next))
		(*path_arg)[*i] = ft_arg(node);
	else if ((*node)->flag_nospace == 0 || ((*node)->flag_nospace == 1
			&& (*node)->next && !ft_not_type((*node)->next)))
		(*path_arg)[*i] = ft_strdup((*node)->str);
	(*i)++;
}

char	**get_arg(t_node *node)
{
	char	**path_arg;
	int		i;
	int		num_arg;

	if (!node)
		return (NULL);
	i = 0;
	num_arg = count_arg(node);
	path_arg = (char **)malloc(sizeof(char *) * (num_arg + 1));
	if (!path_arg)
		return (NULL);
	while (node && i < num_arg)
	{
		if ((ft_not_type(node)))
			ft_set_path_arg(&node, &path_arg, &i);
		if (node->next)
			node = node->next;
	}
	path_arg[i] = NULL;
	return (path_arg);
}
