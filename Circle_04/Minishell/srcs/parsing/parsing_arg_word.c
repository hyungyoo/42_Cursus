/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arg_word.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:57:03 by keulee            #+#    #+#             */
/*   Updated: 2021/11/18 13:10:35 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	argument_word(t_cmd **cmd, char *line, int *index)
{
	int		tmp;
	char	*str;

	tmp = *index;
	while (line[*index] && line[*index] != ' ' && line[*index] != '<' \
		&& line[*index] != '>' && line[*index] != '|' && line[*index] != ';' \
		&& line[*index] != '\"' && line[*index] != '\'' \
		&& line[*index] != '\\' && line[*index] != '$')
		(*index)++;
	if (*index - tmp)
	{
		str = ft_substr(line, tmp, *index - tmp);
		insert_node(cmd, ARG, str);
	}
	(*index)--;
}
