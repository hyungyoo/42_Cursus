/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:09:55 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/13 02:03:30 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*init_cmd(char *str)
{
	char	*ret;
	char	**split_str;

	split_str = ft_split(str, ' ');
	ret = ft_strdup(split_str[0]);
	ft_free_double(split_str);
	split_str = NULL;
	return (ret);
}

char	*init_access_cmd(char *str)
{
	char	*ret;

	(void)str;
	ret = NULL;
	return (ret);
}

int	ft_last_index(char **str)
{
	int		last_index;

	last_index = 0;
	while (str[last_index])
		last_index++;
	--last_index;
	return (last_index);
}

char	**init_cmd_arg(char *str)
{
	char	**ret;
	char	**split_str;
	int		last_index;

	ret = NULL;
	split_str = ft_split(str, ' ');
	last_index = ft_last_index(split_str);
	if (ft_strcmp_pivot(split_str[last_index]) != 0)
	{
		free(split_str[last_index]);
		split_str[last_index] = NULL;
	}
	ret = split_str;
	split_str = NULL;
	return (ret);
}

int	init_flag(char *str)
{
	int		last_index;
	int		ret;
	char	**split_str;

	ret = 0;
	split_str = ft_split(str, ' ');
	last_index = ft_last_index(split_str);
	ret = ft_strcmp_pivot(split_str[last_index]);
	ft_free_double(split_str);
	return (ret);
}

t_parsing	*ft_new_node(char *str)
{
	t_parsing	*new;

	new = (t_parsing *)malloc(sizeof(t_parsing));
	if (!new)
		return (NULL);
	new->cmd = init_cmd(str);
	new->flag = init_flag(str);
	if (ft_strcmp_pivot(new->cmd))
	{
		free(new->cmd);
		new->cmd = NULL;
	}
	new->access_cmd = init_access_cmd(str);
	new->cmd_arg = init_cmd_arg(str);
	new->next = NULL;
	return (new);
}

t_parsing	*ft_last_node(t_parsing *parsing)
{
	if (!parsing)
		return (NULL);
	while (parsing->next)
		parsing = parsing->next;
	return (parsing);
}

void	ft_ajouter_node(t_parsing **parsing, t_parsing *node)
{
	t_parsing	*last;

	if (!*parsing)
	{
		*parsing = node;
		return ;
	}
	last = ft_last_node(*parsing);
	last->next = node;
}

void	ft_free_node(t_parsing *parsing)
{
	free(parsing->cmd);
	free(parsing->access_cmd);
	ft_free_double(parsing->cmd_arg);
}

void	ft_free_all_node(t_parsing **parsing)
{
	t_parsing	*current;
	t_parsing	*next;

	if (!parsing)
		return ;
	current = *parsing;
	while (current)
	{
		next = current->next;
		ft_free_node(current);
		free(current);
		current = next;
	}
	*parsing = NULL;
}
/*
 * to do:
 * 1. initial struct avec g_info.split_cmd
 * 2. ajouter node
 */
void	ft_init_node(t_parsing **parsing, char **split_cmd)
{
	int	i;

	i = 0;
	while (split_cmd[i])
	{
		ft_ajouter_node(parsing, ft_new_node(split_cmd[i]));
		i++;
	}
	ft_free_double(split_cmd);
}
