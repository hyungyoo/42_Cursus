/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_out_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:16:52 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/07/27 14:29:53 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
 * 부모 프로세스는 자식프로세스가 종료되기전 까지, wait함수로 기다리며,
 * 자식 프로세스가 종료되면, 부모 프로세스의 STDIN (표준입력)을 파이프의 출력으로
 * redirection 한후, 표준출력을 output file로 redirection한다.
 */
void	ft_pipe_out_parent(int *pipe_fd, int out_file, char *cmd2, char **envp)
{
	char	**cmd_parsing;

	wait(NULL);
	close(pipe_fd[1]);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		ft_print_error("failed to connect\n");
	if (dup2(out_file, STDOUT_FILENO) == -1)
		ft_print_error("failed to connect\n");
	cmd_parsing = ft_split(cmd2);
	if (cmd_parsing[0][0] == '/')
	{
		if (execve(cmd_parsing[0], cmd_parsing, envp) == -1)
			ft_print_error("commande nor found\n");
	}
	else
		ft_execve(cmd_parsing[0], cmd_parsing, envp);
	ft_free_parsing(cmd_parsing);
	close(pipe_fd[0]);
	close(out_file);
}

/*
 * pipe_fd[1] 을쓴다, 출력이기때문에!
 * 자식 프로세스가 표준출력으로 보내는 모든 데이터가 파이프에 쓰여진다.
 */
void	ft_pipe_in_child(int *pipe_fd, int in_file, char *cmd1, char **envp)
{
	char	**cmd_parsing;

	close(pipe_fd[0]);
	if (dup2(in_file, STDIN_FILENO) == -1)
		ft_print_error("failed to connect\n");
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		ft_print_error("failed to connect\n");
	cmd_parsing = ft_split(cmd1);
	if (cmd_parsing[0][0] == '/')
	{
		if (execve(cmd_parsing[0], cmd_parsing, envp) == -1)
			ft_print_error("commande not found\n");
	}
	else
		ft_execve(cmd_parsing[0], cmd_parsing, envp);
	ft_free_parsing(cmd_parsing);
	close(pipe_fd[1]);
	close(in_file);
}
