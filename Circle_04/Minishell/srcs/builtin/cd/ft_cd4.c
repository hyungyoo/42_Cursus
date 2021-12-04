/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:54:30 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/12/03 10:40:18 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_exec_root_path(char *old_path)
{
	char	*path_env;
	char	*old_pwd;

	chdir("/");
	path_env = ft_strjoin("PWD=", "/");
	old_pwd = ft_strjoin("OLDPWD=", old_path);
	ft_update_path_oldpath(path_env, old_pwd);
	free(path_env);
	free(old_pwd);
}

void	check_root_path(char **path, char *new_path)
{
	char	*tmp;

	tmp = NULL;
	if (new_path[0] == '/')
	{
		tmp = *path;
		*path = ft_strdup("/");
		free(tmp);
	}
}

void	ft_exec_old_path(void)
{
	char	*old_pwd;
	char	*pwd;
	int		flag_chdir;

	if (ft_getenv(g_info.envp, "OLDPWD"))
	{
		flag_chdir = chdir(ft_getenv(g_info.envp, "OLDPWD"));
		if (flag_chdir == -1)
			return ;
		ft_putstr_fd(ft_getenv(g_info.envp, "OLDPWD"), 1);
		ft_putstr_fd("\n", 1);
	}
	pwd = ft_strjoin("PWD=", ft_getenv(g_info.envp, "PWD"));
	old_pwd = ft_strjoin("OLDPWD=", ft_getenv(g_info.envp, "OLDPWD"));
	ft_update_path_oldpath(old_pwd, pwd);
	free(pwd);
	free(old_pwd);
}
