/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:45:50 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/12/03 22:06:08 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_right_fd_pipe(t_node **node, t_fd_pipe *fd, int flag)
{
	if (!(*node)->next || ((*node)->next && (*node)->next->type == PIPE))
	{
		ft_putstr_fd("minishell: syntax error ", 2);
		ft_putstr_fd("near unexpected token 'newline'\n", 2);
		return (0);
	}	
	(*node) = (*node)->next;
	if (check_redir(*node))
	{
		ft_putstr_fd("minisehll: syntax error near unexpected token `>'\n", 2);
		return (0);
	}
	fd->fd_out = open((*node)->str, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd->fd_out == -1)
		return (0);
	if (flag)
	{
		ft_usleep(5);
		dup2(fd->fd_out, 1);
	}
	else
		close(fd->fd_out);
	return (1);
}

int	ft_dright_fd_pipe(t_node **node, t_fd_pipe *fd, int flag)
{
	if (!(*node)->next || ((*node)->next && (*node)->next->type == PIPE))
	{
		ft_putstr_fd("minishell: syntax error ", 2);
		ft_putstr_fd("near unexpected token 'newline'\n", 2);
		return (0);
	}
	(*node) = (*node)->next;
	if (check_redir(*node))
	{
		ft_putstr_fd("minisehll: syntax error near unexpected token `>>'\n", 2);
		return (0);
	}
	fd->fd_out = open((*node)->str, O_CREAT | O_APPEND | O_RDWR, 0644);
	if (fd->fd_out == -1)
		return (0);
	if (flag)
		dup2(fd->fd_out, 1);
	else
		close(fd->fd_out);
	return (1);
}

int	ft_fd_checker_pipe(t_node *node, t_fd_pipe *fd, t_cmd *cmd, int flag)
{
	t_node	*tmp;
	int		flag_exit;
	int		ret;

	flag_exit = 1;
	ret = 1;
	tmp = node->prev;
	while (node != tmp && node->type != PIPE)
	{
		if (node->str && !strcmp(node->str, "<"))
			flag_exit = ft_left_fd_pipe(&node, fd, flag);
		else if (node->str && !strcmp(node->str, "<<"))
			flag_exit = ft_dleft_fd_pipe(&node, fd, cmd, flag);
		else if (node->str && !strcmp(node->str, ">"))
			flag_exit = ft_right_fd_pipe(&node, fd, flag);
		else if (node->str && !strcmp(node->str, ">>"))
			flag_exit = ft_dright_fd_pipe(&node, fd, flag);
		if (!flag_exit)
			ret = 0;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	return (ret);
}

void	ft_set_fd_pipe(t_fd_pipe *fd)
{
	fd->fd_std_in_pipe = dup(fd->pipe_fd[0]);
	fd->fd_std_out_pipe = dup(fd->pipe_fd[1]);
	fd->fd_std_in = dup(0);
	fd->fd_std_out = dup(1);
	fd->fd_in = -1;
	fd->fd_out = -1;
}

void	ft_close_fd_pipe(t_fd_pipe *fd)
{
	dup2(fd->fd_std_in_pipe, fd->fd_std_in);
	dup2(fd->fd_std_out_pipe, fd->fd_std_out);
	if (fd->fd_in != -1)
		close(fd->fd_in);
	if (fd->fd_out != -1)
		close(fd->fd_out);
}
