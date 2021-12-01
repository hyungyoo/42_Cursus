/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:43:09 by keulee            #+#    #+#             */
/*   Updated: 2021/12/01 23:52:07 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	parsing_process(char *str, t_cmd **cmd, int *i)
{
	if (str[*i] == '\"' || str[*i] == '\'')
	{
		if (parsing_quotes(str, i, cmd))
		{
			free(str);
			return (1);
		}
	}
	else if (str[*i] == ';' || str[*i] == '\\')
		return (1);
	else if (str[*i] == '<' || str[*i] == '>' || \
							str[*i] == '|' || str[*i] == '$')
	{
		if (operation_word(cmd, str, i))
		{
			free(str);
			return (1);
		}
	}
	else
		argument_word(cmd, str, i);
	return (0);
}

void	insert_nospace_flag(t_cmd **cmd)
{
	t_node	*node;

	if (!*cmd)
		return ;
	node = (*cmd)->cmd_start;
	while (node)
	{
		if (node->next)
			node = node->next;
		else
			break ;
	}
	if (node)
		node->flag_nospace = 1;
}

int	count_word(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == '\"' && line[i + 1] == '\"')
		{
			if (line[i + 1])
				i = i + 1;
		}
		else
			count++;
		i++;
	}
	return (count);
}

// int	is_emptystr(char *line)
// {
// 	int	i;

// 	i = 0;
// 	while (line)
// }

int	find_cmd_with_emptystr(char *line, char *cmd)
{
	int	index;

	index = 0;
	if (!line || !cmd)
		return (0);
	if (ft_strstr(line, cmd))
	{
		index = ft_strstr(line, cmd) + 1;
		index++;
		while (line[index] && line[index] != '|')
		{
			if ((line[index] == '\"' && line[index + 1] == '\"') \
			|| (line[index] == '\'' && line[index + 1] == '\''))
				return (1);
			index++;
			if (line[index] == '|')
				break ;
		}
	}
	return (0);
}

void	set_export_unset_flag(char *line, int *flag)
{
	int	export;
	int	unset;

	export = 0;
	unset = 0;
	export = find_cmd_with_emptystr(line, "export");
	unset = find_cmd_with_emptystr(line, "unset");
	if (export && !unset)
		*flag = 1;
	else if (!export && unset)
		*flag = 2;
	else if (export && unset)
		*flag = 3;
}
