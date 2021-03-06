/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_out_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 02:38:49 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/07/29 21:49:03 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execute_child(t_info *info)
{
	close(info->pipe_fd[0]);
	dup2(info->fd_input, 0);
	dup2(info->pipe_fd[1], 1);
	close(info->pipe_fd[1]);
	execve(info->cmd1, info->cmd1_parsing, info->envp);
}

void	ft_execute_parent(t_info *info)
{
	close(info->pipe_fd[1]);
	dup2(info->pipe_fd[0], 0);
	dup2(info->fd_output, 1);
	close(info->pipe_fd[0]);
	execve(info->cmd2, info->cmd2_parsing, info->envp);
}

void	ft_pipex(t_info *info)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		ft_print_error("Fork(): fork error.", 1, info);
	else if (pid == 0)
		ft_execute_child(info);
	else if (pid > 0)
	{
		waitpid(pid, &(info->fd_status), WNOHANG);
		ft_execute_parent(info);
	}
}
