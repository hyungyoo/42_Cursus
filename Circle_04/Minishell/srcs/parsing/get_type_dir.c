/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:06:17 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/19 17:28:58 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_redir(t_node *node)
{
	if ((!ft_strcmp((node)->str, "<")) || (!ft_strcmp((node)->str, ">"))
		|| (!ft_strcmp((node)->str, "<<")) || (!ft_strcmp((node)->str, ">>")))
		return (1);
	return (0);
}

void	ft_change_type(t_node **node)
{
	if (!node || !*node)
		return ;
	if (!ft_strcmp((*node)->str, "<"))
		(*node)->type = LEFT;
	else if (!ft_strcmp((*node)->str, "<<"))
		(*node)->type = DLEFT;
	else if (!ft_strcmp((*node)->str, ">"))
		(*node)->type = RIGHT;
	else if (!ft_strcmp((*node)->str, ">>"))
		(*node)->type = DRIGHT;
	if ((*node)->next)
	{
		(*node) = (*node)->next;
		if (!check_redir(*node))
			(*node)->type = FILE;
	}
}

void	ft_type_cmd(t_node *node)
{
	if (!ft_strcmp(node->str, "pwd") || !ft_strcmp(node->str, "cd")
		|| !ft_strcmp(node->str, "env") || !ft_strcmp(node->str, "export")
		|| !ft_strcmp(node->str, "unset") || !ft_strcmp(node->str, "echo")
		|| !ft_strcmp(node->str, "exit"))
		node->type = BUILTIN_CMD;
	else
		node->type = CMD;
}

void	get_type_dir_file(t_node *node)
{
	while (node)
	{
		if (!ft_strcmp(node->str, "|") && node->type == FILE)
			node->type = PIPE;
		if (!ft_strcmp(node->str, "|"))
			node->type = PIPE;
		if (node->next)
			node = node->next;
		else
			return ;
	}
}

void	get_type_dir(t_node *node, t_cmd *cmd)
{
	int	flag_cmd;

	flag_cmd = 0;
	while (node)
	{
		if (ft_check_redir_str(node->str))
			ft_change_type(&node);
		else if (node->type != PIPE && flag_cmd == 0
			&& ((ft_strcmp(node->str, "") && node->type != DOUQ)
				|| (node->type == DOUQ)))
		{
			flag_cmd = 1;
			ft_type_cmd(node);
		}
		if (node->next)
		{
			node = node->next;
			if (node->type == PIPE)
				flag_cmd = 0;
		}
		else
			break ;
	}
	get_type_dir_file(cmd->cmd_start);
}
