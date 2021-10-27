/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:54:30 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/27 11:15:45 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_error_message_cd(char *new_path)
{
	if (new_path)
	{
		ft_putstr("minishell: cd: ");
		ft_putstr(new_path);
		perror(" \b");
	}
	else
	{
		ft_putstr("minishell: cd");
		perror(" ");
	}
	g_info.exit_code = 1;
}

int	ft_new_path(char **path, char *new_path)
{
	free(*path);
	*path = ft_strdup(new_path);
	if (chdir(*path) == -1)
	{
		ft_error_message_cd(*path);
		return (0);
	}
	return (1);
}

static int ft_is_slash(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

char	**ft_split_cd(char *new_path)
{
	char	**ret;
	char	*tmp;

	tmp = NULL;
	ret = NULL;
	if (ft_is_slash(new_path))
		ret = ft_split(new_path, '/');
	else
	{
		tmp = ft_strjoin(new_path, "/");
		ret = ft_split(tmp, '/');
		free(tmp);
		tmp = NULL;
	}
	return (ret);
}

int	ft_exec_dir(char **path, char *new_path)
{
	char	**split_new_path;
	int		i;
	char	*path_tmp;

	split_new_path = NULL;
	path_tmp = NULL;
	if (!new_path)
		return (0);
	if (new_path[0] == '/')
		return (ft_new_path(path, new_path));
	if (!path || !*path)
		return (0);
	split_new_path = ft_split_cd(new_path);
	path_tmp = ft_strdup(*path);
	i = -1;
	while (split_new_path[++i])
	{
		ft_cd_exec(path, split_new_path[i]);
		if (chdir(*path) == -1)
		{
			chdir(path_tmp);
			free(path_tmp);
			ft_error_message_cd(new_path);
			free_tab2(split_new_path);
			return (0);
		}
	}
	free(path_tmp);
	free_tab2(split_new_path);
	return (1);
}

void	ft_exec_home(void)
{
	char	*path_env;
	char	*path;

	path_env = NULL;
	if (ft_getenv(g_info.envp, "HOME"))
		path = ft_strdup(ft_getenv(g_info.envp, "HOME"));
	else
		path = NULL;
	if (chdir(path) == -1)
	{
		ft_error_message_cd(path);
	}
	else
	{
		path_env = ft_strjoin("PWD=", path);
		ft_update_env(g_info.envp, path_env, "PWD");
		free(path_env);
		g_info.exit_code = 0;
	}
	free(path);
}

void	ft_exec_path(char *new_path)
{
	char	*path;
	char	*path_env;

	path_env = NULL;
	if (ft_getenv(g_info.envp, "PWD"))
		path = ft_strdup(ft_getenv(g_info.envp, "PWD"));
	else
		path = NULL;
	if (ft_exec_dir(&path, new_path))
	{
		path_env = ft_strjoin("PWD=", path);
		ft_update_env(g_info.envp, path_env, "PWD");
		free(path_env);
		g_info.exit_code = 0;
	}
	free(path);
}

void	ft_cd(t_node **cmd)
{
	char	*new_path;

	new_path = NULL;
	if ((*cmd)->next)
	{
		(*cmd) = (*cmd)->next;
		new_path = ft_strdup((*cmd)->str);
		if (!ft_strcmp(new_path, "~"))
			ft_exec_home();
		else
			ft_exec_path(new_path);
	}
	free(new_path);
}
