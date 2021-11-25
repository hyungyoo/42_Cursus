/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:59:28 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/25 18:53:48 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_expension_quote(t_cmd *cmd, t_node *node)
{
	(void)cmd;
	while (node)
	{
		if (node->type == DOLR)
		{
			if (node->next && (node->next->type == DOUQ
					|| node->next->type == SINQ))
				ft_clear_dolr_quote(cmd, &node);
		}
		if (node->next)
			node = node->next;
		else
			return ;
	}
}

void	ft_expension_num_quote(t_cmd *cmd)
{
	t_node	*node;

	if (!cmd)
		return ;
	node = cmd->cmd_start;
	ft_expension_num(cmd, node);
	ft_expension_quote(cmd, node);
}
