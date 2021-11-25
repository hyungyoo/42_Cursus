/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:59:28 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/23 16:32:02 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_del_list_one_node(t_cmd *cmd, t_node *node)
{
	cmd->cmd_start = NULL;
	free(node->str);
	free(node);
}

void	ft_del_list_last_node(t_cmd *cmd, t_node *node)
{
	(void)cmd;
	node->prev->next = NULL;
	free(node->str);
	free(node);
}

void	ft_del_list(t_cmd *cmd, t_node *node)
{
	int	size_node;

	size_node = cmd->size;
	if (size_node == 1)
		ft_del_list_one_node(cmd, node);
	else if (!(node->next) || size_node == 2)
		ft_del_list_last_node(cmd, node);
	else if (node->next)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		free(node->str);
		free(node);
	}
}

void	ft_reset_value_exit_code(t_cmd *cmd, t_node **node)
{
	char	*tmp;
	t_node	*next_node;

	tmp = NULL;
	if (!node || !(*node) || !((*node)->next))
		return ;
	next_node = (*node)->next;
	tmp = (*node)->str;
	if (!ft_strcmp((next_node)->str, "?"))
		(*node)->str = ft_itoa(g_info.exit_code);
	else if (!ft_strcmp((next_node)->str, "$"))
		(*node)->str = ft_strdup("53017");
	(*node)->type = ARG;
	(*node)->flag_nospace = next_node->flag_nospace;
	free(tmp);
	ft_del_list(cmd, next_node);
}

void	ft_reset_value(t_cmd *cmd, t_node **node)
{
	char	*tmp;
	t_node	*next_node;

	tmp = NULL;
	if (!node || !(*node) || !((*node)->next))
		return ;
	next_node = (*node)->next;
	tmp = (*node)->str;
	(*node)->str = ft_strjoin("$", (next_node->str));
	(*node)->type = ARG;
	(*node)->flag_nospace = next_node->flag_nospace;
	free(tmp);
	ft_del_list(cmd, next_node);
}
