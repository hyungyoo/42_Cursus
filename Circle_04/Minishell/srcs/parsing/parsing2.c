/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:43:09 by keulee            #+#    #+#             */
/*   Updated: 2021/12/01 17:06:37 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*dquote_removed_str(char *line, int count)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (count + 1));
	while (line[i])
	{
		if (line[i] == '\"' && line[i + 1] == '\"')
		{
			if (line[i + 1])
				i = i + 1;
		}
		else
		{
			str[j] = line[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*remove_quote(char *line, int *flag)
{
	int		count;

	count = count_word(line);
	if (ft_strstr(line, "export") || ft_strstr(line, "unset"))
		set_export_unset_flag(line, flag);
	return (dquote_removed_str(line, count));
}

int	ft_parsing(char *line, t_cmd **cmd)
{
	int		i;
	char	*str;
	int		flag;

	flag = 0;
	if (!ft_strcmp(line, "\"\"") || !ft_strcmp(line, "\'\'"))
	{
		insert_node(cmd, ARG, ft_strdup(""));
		return (0);
	}
	str = remove_quote(line, &flag);
	i = -1;
	while (str[++i])
	{
		while (str[i] == ' ')
			i++;
		if (parsing_process(str, cmd, &i) == 1)
			return (1);
		if (str[i + 1] && str[i + 1] != ' ' && str[i + 1] != '\0')
			insert_nospace_flag(cmd);
	}
	emptystr_managing(cmd, flag);
	free(str);
	return (0);
}
