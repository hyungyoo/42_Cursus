/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 22:08:23 by cclaude           #+#    #+#             */
/*   Updated: 2021/10/31 02:03:20 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	openfile (char *filename, int mode)
{
	if (mode == INFILE)
	{
		if (access(filename, F_OK))
		{
			write(STDERR, "pipex: ", 7);
			write(STDERR, filename, str_ichr(filename, 0));
			write(STDERR, ": No such file or directory\n", 28);
			return (STDIN);
		}
		return (open(filename, O_RDONLY));
	}
	else
		return (open(filename, O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH));
}

char	*getPath (char *cmd, char **env)
{
	char	*path;
	char	*dir;
	char	*bin;
	int		i;

	i = 0;
	while (env[i] && str_ncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (cmd);
	path = env[i] + 5;
	while (path && str_ichr(path, ':') > -1)
	{
		dir = str_ndup(path, str_ichr(path, ':'));
		bin = path_join(dir, cmd);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += str_ichr(path, ':') + 1;
	}
	return (cmd);
}

void	exec (char *cmd, char **env)
{
	char	**args;
	char	*path;

	args = str_split(cmd, ' ');
	if (str_ichr(args[0], '/') > -1)
		path = args[0];
	else
		path = getPath(args[0], env);
	execve(path, args, env);
	write(STDERR, "pipex: ", 7);
	write(STDERR, cmd, str_ichr(cmd, 0));
	write(STDERR, ": command not found\n", 20);
	exit(127);
}

void	redir (char *cmd, char **env, int fdin)
{
	pid_t	pid;
	int		pipefd[2];

	(void)fdin;
	int	fd_in;
	pipe(pipefd);
	pid = fork();
	if (pid)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(pipefd[0]);
		fd_in = openfile("./txt", INFILE);
		dup2(fd_in, STDIN);
		dup2(pipefd[1], STDOUT);
		exec(cmd, env);
	}
}

#include <stdio.h>
int	main (int ac, char **av, char **env)
{
	int	i;

	//int	fd_in;
	i = 1;
	if (ac >= 2)
	{
		while (i < ac - 1)
		{
			//fd_in = openfile("./txt", INFILE);
			//dup2(fd_in, STDIN);
			redir(av[i++], env, 1);
		}
		// last one, not pipe
		exec(av[i], env);
	}
	else
		write(STDERR, "Invalid number of arguments.\n", 29);
	return (1);
}
