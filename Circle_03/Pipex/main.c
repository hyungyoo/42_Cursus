/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:17:28 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/07/27 14:29:39 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
 * ft_execuve -> path + cmd + envp
 * 1. 인자로 들어온 envp를 돌아보며,  PATH가 있는지확인
 * 2. 찾았다면, 그 PATH= 까지는 날려버리고, ':'를 기준으로 parsing
 *
 * 1 과 2는
 * char		**ft_path 함수로, parsing한 PATH를 반환
 *
 * 3. access 함수로, 실제로 가능한 실행파일 경로인지를 확인 후
 * 4. execve 함수 실행
 * 없다면 command not found!
 */

void	ft_end(char **path_parsing, int size_path_parsing, int i)
{
	ft_free_parsing(path_parsing);
	if (i == size_path_parsing)
		ft_print_error("No sush command found\n");
}

void	ft_execve(char *cmd, char **cmd_parsing, char **envp)
{
	char	**path_parsing;
	int		size_path_parsing;
	int		i;
	char	*path_br;
	char	*path_br_cmd;

	i = -1;
	path_parsing = ft_path_parsing(envp);
	size_path_parsing = ft_size_parsing(path_parsing);
	while (++i < size_path_parsing)
	{
		path_br = ft_strjoin(path_parsing[i], "/");
		path_br_cmd = ft_strjoin(path_br, cmd);
		if (access(path_br_cmd, R_OK | X_OK) == 0)
		{
			execve(path_br_cmd, cmd_parsing, envp);
			free(path_br);
			free(path_br_cmd);
			break ;
		}
		free(path_br);
		free(path_br_cmd);
	}
	ft_end(path_parsing, size_path_parsing, i);
}

void	ft_init(int argc, int	**pipe_fd)
{
	if (argc != 5)
		ft_print_error("to use : ./pipex file1 cmd1 cmd2 fil2\n");
	*pipe_fd = (int *)malloc(sizeof(int) * 2);
	if (!(*pipe_fd))
		ft_print_error("error malloc\n");
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		in_file;
	int		out_file;
	int		*pipe_fd;

	ft_init(argc, &pipe_fd);
	if (pipe(pipe_fd) == -1)
		ft_print_error("failed to open pipe\n");
	in_file = open(argv[1], O_RDONLY);
	out_file = open(argv[4], O_WRONLY);
	if ((in_file) == -1)
		ft_print_error("failed to open in_file\n");
	else if ((out_file) == -1)
		ft_print_error("failed to open out_file\n");
	pid = fork();
	if (pid > 0)
		ft_pipe_out_parent(pipe_fd, out_file, argv[3], envp);
	else if (pid == 0)
		ft_pipe_in_child(pipe_fd, in_file, argv[2], envp);
	else
		ft_print_error("failed to fork the process\n");
	return (0);
}
