/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:41:48 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/19 17:38:00 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_dleft_fd(t_node **node, t_fd *fd, t_cmd *cmd)
{
	int	status;

	status = 0;
	if (!(*node)->next)
	{
		ft_putstr_fd("minishell: parse error near\n", 2);
		return (0);
	}	
	else if (check_redir(*node))
	{
		ft_putstr_fd("minisehll: syntax error near unexpected token `<<'\n", 2);
		return (0);
	}
	pipe(fd->fd_heredoc_pipe);
	g_info.pid_child = fork();
	(*node) = (*node)->next;
	if (g_info.pid_child > 0)
		heredoc_parent(fd, status);
	else if (g_info.pid_child == 0)
		heredoc_child(fd, cmd, node);
	return (1);
}

int	ft_right_fd(t_node **node, t_fd *fd)
{
	if (!(*node)->next)
	{
		ft_putstr_fd("minishell: syntax error ", 2);
		ft_putstr_fd("near unexpected token 'newline'\n", 2);
		return (0);
	}	
	else if(check_redir(*node))
	{
		ft_putstr_fd("minisehll: syntax error near unexpected token `>'\n", 2);
		return (0);
	}
	(*node) = (*node)->next;
	fd->fd_out = open((*node)->str, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd->fd_out == -1)
		return (0);
	dup2(fd->fd_out, 1);
	return (1);
}

int	ft_dright_fd(t_node **node, t_fd *fd)
{
	if (!(*node)->next)
	{
		ft_putstr_fd("minishell: syntax error ", 2);
		ft_putstr_fd("near unexpected token 'newline'\n", 2);
		return (0);
	}
	else if (check_redir(*node))
	{
		ft_putstr_fd("minisehll: syntax error near unexpected token `>>'\n", 2);
		return (0);
	}
	(*node) = (*node)->next;
	fd->fd_out = open((*node)->str, O_CREAT | O_APPEND | O_RDWR, 0644);
	if (fd->fd_out == -1)
		return (0);
	dup2(fd->fd_out, 1);
	return (1);
}

int	ft_fd_checker(t_node *node, t_fd *fd, t_cmd *cmd)
{
	t_node	*tmp;
	int		flag_exit;

	flag_exit = 1;
	tmp = node->prev;
	while (node != tmp && node->type != PIPE)
	{
		if (node->str && !strcmp(node->str, "<"))
			flag_exit = ft_left_fd(&node, fd);
		else if (node->str && !strcmp(node->str, "<<"))
			flag_exit = ft_dleft_fd(&node, fd, cmd);
		else if (node->str && !strcmp(node->str, ">"))
			flag_exit = ft_right_fd(&node, fd);
		else if (node->str && !strcmp(node->str, ">>"))
			flag_exit = ft_dright_fd(&node, fd);
		if (!flag_exit)
			return (0);
		if (node->next)
			node = node->next;
		else
			break ;
	}
	return (1);
}

void	ft_execve_cmd(t_node **node, t_cmd *cmd)
{
	int	status;

	g_info.pid_child = fork();
	if (g_info.pid_child == 0)
	{
		ft_execmd(*node, cmd);
		ft_exit_minishell(g_info.exit_code, &cmd);
	}
	else if (g_info.pid_child > 0)
	{
		waitpid(g_info.pid_child, &status, 0);
		g_info.pid_child = 0;
		g_info.exit_code = WEXITSTATUS(status);
	}
}
