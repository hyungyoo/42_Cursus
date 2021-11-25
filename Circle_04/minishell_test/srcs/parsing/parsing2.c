/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:43:09 by keulee            #+#    #+#             */
/*   Updated: 2021/11/25 18:56:58 by hyungyoo         ###   ########.fr       */
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

void	put_emptystr_flag(t_cmd **cmd, int flag)
{
	t_node	*node;

	if (!(*cmd) || !cmd)
		return ;
	node = (*cmd)->cmd_start;
	while (node)
	{
		if (!(ft_strcmp(node->str, "export")) && flag == 1)
			node->flag_emptystr = 1;
		else if (!(ft_strcmp(node->str, "unset")) && flag == 2)
			node->flag_emptystr = 1;
		else if (flag == 3 && (!(ft_strcmp(node->str, "export")) \
			|| !ft_strcmp(node->str, "unset")))
			node->flag_emptystr = 1;
		else
			node->flag_emptystr = 0;
		if (node->next)
			node = node->next;
		else
			break ;
	}
}

void	init_emptystr_flag(t_cmd **cmd)
{
	t_node	*node;

	node = (*cmd)->cmd_start;
	while (node)
	{
		node->flag_emptystr = 0;
		if (node->next)
			node = node->next;
		else
			break ;
	}
}

int	ft_parsing(char *line, t_cmd **cmd)
{
	int		i;
	char	*str;
	int		flag;

	flag = 0;
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
	init_emptystr_flag(cmd);
	if (flag)
		put_emptystr_flag(cmd, flag);
	free(str);
	return (0);
}
