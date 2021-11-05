/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_detail_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 03:36:35 by keulee            #+#    #+#             */
/*   Updated: 2021/11/04 03:36:36 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_builtin(char *str)
{
	if (!ft_strcmp(str, "echo"))
		return (1);
	else if (!ft_strcmp(str, "pwd"))
		return (1);
	else if (!ft_strcmp(str, "export"))
		return (1);
	else if (!ft_strcmp(str, "cd"))
		return (1);
	else if (!ft_strcmp(str, "unset"))
		return (1);
	else if (!ft_strcmp(str, "env"))
		return (1);
	else if (!ft_strcmp(str, "exit"))
		return (1);
	return (0);
}

int	is_operation_word(t_node *node)
{
	if (node->type == LEFT || node->type == RIGHT || node->type == DRIGHT)
		return (0);
	return (1);
}

void	first_cmd_type(t_cmd **cmd)
{
	t_node	*tmp;

	tmp = (*cmd)->cmd_start;
	if (is_builtin(tmp->str))
		tmp->type = BUILTIN_CMD;
	else
		tmp->type = CMD;
}

void	set_cmd_next_pipe(t_node *tmp)
{
	if (tmp->next && tmp->next->type == ARG)
	{
		if (is_builtin(tmp->next->str))
			tmp->next->type = BUILTIN_CMD;
		else
			tmp->next->type = CMD;
	}
}

void	set_detail_type(t_cmd **cmd)
{
	t_node	*tmp;

	if (!*cmd || !(*cmd)->cmd_start)
		return ;
	first_cmd_type(cmd);
	tmp = (*cmd)->cmd_start->next;
	while (tmp)
	{
		if (!is_operation_word(tmp))
		{
			if (tmp->next)
				tmp->next->type = FILE;
		}
		if (tmp->type == DLEFT)
		{
			if (tmp->next)
				tmp->next->type = LIMITER;
		}
		if (tmp->type == PIPE)
			set_cmd_next_pipe(tmp);
		tmp = tmp->next;
	}
}
