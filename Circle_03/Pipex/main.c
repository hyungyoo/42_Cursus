/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 02:39:27 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/08 07:50:15 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_check_pipex_error(t_info **info)
{
	if ((*info)->fd_input < 0)
	{
		free(*info);
		ft_put_error_str(strerror(errno), 0);
	}
	if ((*info)->fd_output < 0)
	{
		free(*info);
		ft_put_error_str(strerror(errno), 0);
	}
	(*info)->cmd1_parsing = ft_split((*info)->cmd1, ' ');
	ft_cmd_path(info, 1);
	(*info)->cmd2_parsing = ft_split((*info)->cmd2, ' ');
	ft_cmd_path(info, 2);
}

void	ft_double_free(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	ft_malloc_free(t_info *info)
{
	ft_double_free(info->cmd1_parsing);
	ft_double_free(info->cmd2_parsing);
	free(info->cmd1);
	free(info->cmd2);
	close(info->pipe_fd[1]);
	close(info->fd_input);
	close(info->fd_output);
	free(info);
}

void	ft_put_error_str(char *str, int err)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
	exit(err);
}

int	main(int argc, char **argv, char **envp)
{
	t_info	*info;

	info = NULL;
	if (argc != 5)
		ft_put_error_str("to use: '> ./pipex file1 cmd1 cmd2 file2'.", 1);
	info = (t_info *)malloc(sizeof(t_info));
	if (pipe(info->pipe_fd) == -1)
		ft_put_error_str("Pipe(): pipe error.", 1);
	info->fd_input = open(argv[1], O_RDONLY);
	info->fd_output = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	info->envp = envp;
	info->cmd1 = argv[2];
	info->cmd2 = argv[3];
	ft_check_pipex_error(&info);
	ft_pipex(info);
	ft_malloc_free(info);
	return (0);
}
