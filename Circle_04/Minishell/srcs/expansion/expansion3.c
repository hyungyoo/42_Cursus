/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:59:28 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/23 02:36:25 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_ajouter_dolr_code(char **new_str, int *i)
{
	char	*num;

	num = NULL;
	num = ft_strdup("53017");
	*new_str = ft_strjoin_free(*new_str, num);
	free(num);
	(*i) = (*i) + 2;
}
/*
if (((*node)->str)[i] == '$' && ((*node)->str)[i + 1]
			&& ((*node)->str)[i + 1] && ((*node)->str)[i + 1] != '?'
			&& ((*node)->str)[i + 1] != '$' && ((*node)->str)[i + 1] != ' ')
			ft_ajouter_dolr(&new_str, (*node)->str, &(i));
*/
void	ft_reset_value_douq(t_cmd *cmd, t_node **node)
{
	char	*new_str;
	char	*tmp;
	int		i;

	(void)cmd;
	i = 0;
	new_str = NULL;
	tmp = (*node)->str;
	while (((*node)->str)[i])
	{
		if (((*node)->str)[i] == '$' && ((*node)->str)[i + 1]
			&& ((*node)->str)[i + 1] != '?' && ((*node)->str)[i + 1] != '$'
				&& !check_exit_char(((*node)->str)[i + 1]))
			ft_ajouter_dolr(&new_str, (*node)->str, &(i));
		else if (((*node)->str)[i] == '$' && ((*node)->str)[i + 1]
			&& ((*node)->str)[i + 1] == '?')
			ft_ajouter_exit_code(&new_str, &(i));
		else if (((*node)->str)[i] == '$' && ((*node)->str)[i + 1]
			&& ((*node)->str)[i + 1] == '$')
			ft_ajouter_dolr_code(&new_str, &(i));
		else
			ft_ajouter_char(&new_str, (((*node)->str)[i++]));
	}
	(*node)->str = new_str;
	free(tmp);
}

void	ft_expension(t_cmd **cmd)
{
	t_node	*node;

	printf("hello\n");
	node = (*cmd)->cmd_start;
	while (node)
	{
		if (node->type == DOLR && node->flag_nospace == 1 && node->next
			&& node->next->type == ARG && (ft_strcmp(node->next->str, "?")
				&& ft_strcmp(node->next->str, "$")))
			ft_reset_value(*cmd, &node);
		else if (node->type == DOLR && node->flag_nospace == 1 && node->next
			&& (!ft_strcmp(node->next->str, "?")
				|| !ft_strcmp(node->next->str, "$")))
			ft_reset_value_exit_code(*cmd, &node);
		else if (node->type == DOUQ)
			ft_reset_value_douq(*cmd, &node);
		if (node->next)
			node = node->next;
		else
			return ;
	}
}
