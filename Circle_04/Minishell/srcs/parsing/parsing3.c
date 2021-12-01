/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:08:49 by keulee            #+#    #+#             */
/*   Updated: 2021/12/01 17:08:51 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

void	emptystr_managing(t_cmd **cmd, int flag)
{
	init_emptystr_flag(cmd);
	if (flag)
		put_emptystr_flag(cmd, flag);
}
