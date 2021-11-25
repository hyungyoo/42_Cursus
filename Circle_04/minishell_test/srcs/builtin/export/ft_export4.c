/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:35:32 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/25 18:31:14 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_check_arg(t_node *node)
{
	while (node && node->type != PIPE)
	{
		if (ft_strcmp(node->str, "") && (node->type == ARG
				|| node->type == SINQ || node->type == DOUQ))
			return (1);
		if (node->next)
			node = node->next;
		else
			break ;
	}
	return (0);
}

int	ft_size_array_export(t_node *cmd)
{
	int		ret;

	ret = 0;
	if (!cmd)
		return (-1);
	while (cmd && cmd->type != PIPE)
	{
		if (cmd->flag_nospace == 0 && ft_not_type(cmd))
			ret++;
		if (cmd->next)
			cmd = cmd->next;
		else
			break ;
	}
	return (ret);
}

void	strjoin_array_export(char ***array_export, int *i,
		t_node **cmd, int size_array)
{
	while (*i < size_array)
	{
		(*array_export)[*i] = NULL;
		if (ft_not_type(*cmd))
		{
			while (*cmd && ft_not_type(*cmd) && (*cmd)->flag_nospace == 1)
			{
				(*array_export)[*i] = ft_strjoin_free((*array_export)[*i],
						(*cmd)->str);
				if ((*cmd)->next)
					(*cmd) = (*cmd)->next;
				else
					break ;
			}
			if ((*cmd) && ft_not_type(*cmd))
				(*array_export)[*i] = ft_strjoin_free((*array_export)[*i],
						(*cmd)->str);
			(*i)++;
		}
		if ((*cmd)->next)
			*cmd = (*cmd)->next;
		else
			break ;
	}
}

char	**ft_array_double_export(t_node *cmd)
{
	char	**array_export;
	int		i;
	int		size_array;

	i = 0;
	size_array = ft_size_array_export(cmd);
	array_export = (char **)malloc(sizeof(char *) * (size_array + 1));
	if (!array_export)
		return (NULL);
	strjoin_array_export(&array_export, &i, &cmd, size_array);
	array_export[i] = NULL;
	return (array_export);
}

char	**ft_new_array_export(char **str, int size)
{
	char	**ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = (char **)malloc(sizeof(char *) * (size + 1));
	if (!ret)
		return (NULL);
	while (str[i])
	{
		if (!(!ft_check_str(str[i]) || !ft_strcmp(str[i], "=")
				|| !ft_check_egal(str[i]) || ft_check_value(str[i])))
			ret[j++] = ft_strdup(str[i++]);
		else
			i++;
	}
	ret[j] = NULL;
	free_tab2(str);
	return (ret);
}
