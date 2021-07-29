/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 02:39:50 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/07/29 02:39:51 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_path(char **envp)
{
	int		i;
	char	*new_path;

	i = 0;
	new_path = NULL;
	while (envp[i])
	{
		if (!ft_strncmp("PATH=", envp[i], 5))
		{
			new_path = ft_strdup(ft_strrchr(envp[i], '=') + 1);
			break ;
		}
		i++;
	}
	return (new_path);
}

int	ft_verifier_paths(char *path, char **cmd, char *path_parsing)
{
	char	*tmp_cmd;
	char	*tmp;

	tmp_cmd = ft_strjoin(path, "/");
	tmp = tmp_cmd;
	tmp_cmd = ft_strjoin(tmp_cmd, path_parsing);
	free(tmp);
	if (access(tmp_cmd, R_OK | X_OK) == 0)
	{
		*cmd = ft_strdup(tmp_cmd);
		free(tmp_cmd);
		return (1);
	}
	free(tmp_cmd);
	return (0);
}

void	ft_cmd_path(t_info **info, int cmd_n)
{
	int		i;
	char	*path;
	char	**path_parsing;
	int		flag;

	flag = 0;
	path = ft_get_path((*info)->envp);
	path_parsing = ft_split(path, ':');
	i = -1;
	while (path_parsing[++i] && !flag)
	{
		if (cmd_n == 1)
			flag = ft_verifier_paths(path_parsing[i], &(*info)->cmd1,
					(*info)->cmd1_parsing[0]);
		else if (cmd_n == 2)
			flag = ft_verifier_paths(path_parsing[i], &(*info)->cmd2,
					(*info)->cmd2_parsing[0]);
	}
	free(path);
	i = 0;
	while (path_parsing[i])
		free(path_parsing[i++]);
	free(path_parsing);
	if (!flag)
		ft_print_error("Command not found.", 127);
}

void	ft_print_error(char *str, int err)
{
	write(1, "Error: ", 8);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(err);
}
