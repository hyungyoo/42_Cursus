/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:54:30 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/12/03 10:54:28 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_exec_chdir(char **path, char *new_path, char *path_tmp,
		char **split_new_path)
{
	int	i;

	i = 0;
	check_root_path(path, new_path);
	while (split_new_path[i])
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
		i++;
	}
	return (1);
}

int	ft_exec_dir(char **path, char *new_path)
{
	char	**split_new_path;
	char	*path_tmp;

	split_new_path = NULL;
	path_tmp = NULL;
	split_new_path = ft_split_cd(new_path);
	path_tmp = ft_strdup(*path);
	if (!(ft_exec_chdir(path, new_path, path_tmp, split_new_path)))
		return (0);
	free(path_tmp);
	free_tab2(split_new_path);
	return (1);
}

int	ft_get_path_home(char **path, char *str)
{
	if (!str && (!ft_getenv(g_info.envp, "HOME")
			|| !ft_strcmp(ft_getenv(g_info.envp, "HOME"), "")))
	{
		g_info.exit_code = 1;
		if (!ft_chercher_key(g_info.envp, "HOME"))
			ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		return (0);
	}
	g_info.exit_code = 0;
	*path = ft_strdup(g_info.home);
	return (1);
}

void	ft_update_path_oldpath(char *path_env, char *old_pwd)
{
	ft_update_env(g_info.envp, path_env, "PWD");
	ft_update_env(g_info.envp, old_pwd, "OLDPWD");
	g_info.exit_code = 0;
	g_info.flag_pwd = 0;
}

void	ft_exec_home(char *str)
{
	char	*path_env;
	char	*path;
	char	*old_path;
	char	*old_pwd;

	path_env = NULL;
	path = NULL;
	if (!ft_get_path_home(&path, str))
		return ;
	if (g_info.flag_pwd == 1)
		old_path = ft_strdup("");
	else
		old_path = ft_strdup(ft_getenv(g_info.envp, "PWD"));
	if ((chdir(path)) == -1)
		ft_error_message_cd(path);
	else
	{
		path_env = ft_strjoin("PWD=", path);
		old_pwd = ft_strjoin("OLDPWD=", old_path);
		ft_update_path_oldpath(path_env, old_pwd);
		free(path_env);
		free(old_pwd);
	}
	free(path);
	free(old_path);
}
