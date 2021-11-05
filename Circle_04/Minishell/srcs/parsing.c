/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:43:09 by keulee            #+#    #+#             */
/*   Updated: 2021/11/04 00:43:10 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	parsing_process(char *line, t_cmd **cmd, int *i)
{
	if (line[*i] == '\"' || line[*i] == '\'')
	{
		if (parsing_quotes(line, i, cmd))
			return (1);
	}
	else if (line[*i] == ';' || line[*i] == '\\')
		return (1);
	else if (line[*i] == '<' || line[*i] == '>' || \
							line[*i] == '|' || line[*i] == '$')
	{
		if (operation_word(cmd, line, i))
			return (1);
	}
	else
		argument_word(cmd, line, i);
	return (0);
}

void	insert_nospace_flag(t_cmd **cmd)
{
	t_node	*node;

	if (!*cmd)
		return ;
	node = (*cmd)->cmd_start;
	while (node->next != NULL)
		node = node->next;
	node->flag_nospace = 1;
}

int	ft_parsing(char *line, t_cmd **cmd)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		while (line[i] == ' ')
			i++;
		if (parsing_process(line, cmd, &i) == 1)
			return (1);
		if (line[i + 1] != ' ' && line[i + 1] != '\0')
			insert_nospace_flag(cmd);
	}
	return (0);
}
