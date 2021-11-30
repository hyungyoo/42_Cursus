/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:54:30 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/30 19:32:44 by hyungyoo         ###   ########.fr       */
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
