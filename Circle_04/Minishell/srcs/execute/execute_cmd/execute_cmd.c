/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:43:25 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/18 12:43:42 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*get_path(char *str)
{
	char	**split_path;
	int		i;
	char	*tmp1;
	char	*tmp2;

	i = -1;
	if (str[0] == '/')
		return (ft_strdup(str));
	split_path = ft_split(ft_getenv(g_info.envp, "PATH"), ':');
	while (split_path[++i])
	{
		tmp1 = ft_strjoin(split_path[i], "/");
		tmp2 = ft_strjoin(tmp1, str);
		free(tmp1);
		if (access(tmp2, F_OK | X_OK) == 0)
		{
			free_tab2(split_path);
			return (tmp2);
		}
		free(tmp2);
	}
	free_tab2(split_path);
	return (ft_strdup(str));
}

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

char	**get_arg(t_node *node)
{
	char	**path_arg;
	int		i;
	int		num_arg;

	i = 0;
	if (!node)
		return (NULL);
	num_arg = count_arg(node);
	path_arg = (char **)malloc(sizeof(char *) * (num_arg + 1));
	if (!path_arg)
		return (NULL);
	while (node && i < num_arg)
	{
		if ((ft_not_type(node)))
		{
			if (node->flag_nospace == 1 && node->next
				&& ft_not_type(node->next))
				path_arg[i] = ft_arg(&node);
			else if (node->flag_nospace == 0 || (node->flag_nospace == 1
					&& node->next && !ft_not_type(node->next)))
				path_arg[i] = ft_strdup(node->str);
			i++;
		}
		if (node->next)
			node = node->next;
	}
	path_arg[i] = NULL;
	return (path_arg);
}
