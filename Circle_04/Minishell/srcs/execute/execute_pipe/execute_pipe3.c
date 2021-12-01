/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:45:50 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/12/01 21:53:52 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	execute_cmds_pipe(t_node **node, t_cmd *cmd, t_fd_pipe *fd)
{
	t_node	*tmp;

	ft_set_fd_pipe(fd);
	if (ft_fd_checker_pipe(*node, fd, cmd, check_cmd(*node)))
	{
		ft_close_fd_pipe(fd);
		tmp = (*node)->prev;
		while ((*node) != tmp)
		{
			if ((*node)->type == CMD || (*node)->type == BUILTIN_CMD)
				break ;
			if ((*node)->next)
				(*node) = (*node)->next;
			else
				break ;
		}
		if ((*node)->type == BUILTIN_CMD)
			ft_built_in(node, cmd);
		else if ((*node)->type == CMD)
			ft_execmd(*node, cmd);
	}
}

int	check_next_pipe_node(t_node **node)
{
	while (*node)
	{
		if ((*node)->type == PIPE)
		{
			if ((*node)->next)
			{
				(*node) = (*node)->next;
				return (TRUE);
			}
		}
		if ((*node)->next)
			(*node) = (*node)->next;
		else
			break ;
	}
	return (FALSE);
}

int	check_dleft(t_node *node)
{
	int	flag_redir;

	flag_redir = node->type;
	if (node->next)
		node = node->next;
	while (node && node->type != PIPE)
	{
		if (node->type == LEFT || node->type == DLEFT)
			flag_redir = 0;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	return (flag_redir);
}

int	check_dleft_next_cmd(t_node *node)
{
	int	flag_redir;

	flag_redir = 0;
	while (node && node->type != PIPE)
	{
		if (node->type == LEFT)
			flag_redir = LEFT;
		else if (node->type == DLEFT)
			flag_redir = DLEFT;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	return (flag_redir);
}

int	check_dleft_file(t_node *node)
{
	int	flag_file;

	flag_file = TRUE;
	while (node)
	{
		if (node->type == DLEFT)
		{
			if (node->next && node->next->type == FILE)
				flag_file = TRUE;
			else
				flag_file = FALSE;
		}
		if (node->next)
			node = node->next;
		else
			break ;
	}
	return (flag_file);
}
