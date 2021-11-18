/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:58:32 by keulee            #+#    #+#             */
/*   Updated: 2021/11/18 13:10:48 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	parsing_quotes(char *str, int *index, t_cmd **cmd)
{
	int		tmp;
	char	*string;
	char	pair;

	pair = str[(*index)++];
	tmp = *index;
	if (is_quotes_pair(str, index, pair))
		return (EXIT_FAILURE);
	while (str[*index] && str[*index] != pair)
		(*index)++;
	string = ft_substr(str, tmp, *index - tmp);
	if (*index - tmp)
	{
		if (pair == '\"')
			insert_node(cmd, DOUQ, string);
		else if (pair == '\'')
			insert_node(cmd, SINQ, string);
	}
	return (EXIT_SUCCESS);
}

int	is_quotes_pair(char *str, int *index, char pair)
{
	int	tmp;

	tmp = *index;
	while (str[tmp])
	{
		if (str[tmp] == pair)
			return (0);
		tmp++;
	}
	return (1);
}
