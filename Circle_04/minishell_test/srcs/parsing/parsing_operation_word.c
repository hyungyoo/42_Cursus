/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_operation_word.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:55:40 by keulee            #+#    #+#             */
/*   Updated: 2021/11/18 13:10:41 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	parsing_left(char *line, t_cmd **cmd, int *index)
{
	if (line[(*index) + 1] == '<')
	{
		insert_node(cmd, DLEFT, ft_strdup("<<"));
		(*index)++;
	}
	else
		insert_node(cmd, LEFT, ft_strdup("<"));
}

void	parsing_right(char *line, t_cmd **cmd, int *index)
{
	if (line[(*index) + 1] == '>')
	{
		insert_node(cmd, DRIGHT, ft_strdup(">>"));
		(*index)++;
	}
	else
		insert_node(cmd, RIGHT, ft_strdup(">"));
}

int	operation_word(t_cmd **cmd, char *line, int *index)
{
	if (!ft_strncmp(&line[*index], "<", 1))
		parsing_left(line, cmd, index);
	else if (!ft_strncmp(&line[*index], ">", 1))
		parsing_right(line, cmd, index);
	else if (!ft_strncmp(&line[*index], "|", 1))
	{
		if (line[(*index) + 1] == '|')
			return (1);
		else
			insert_node(cmd, PIPE, ft_strdup("|"));
	}
	else if (!ft_strncmp(&line[*index], "$", 1))
		insert_node(cmd, DOLR, ft_strdup("$"));
	return (0);
}
