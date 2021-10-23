/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:54:30 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/23 04:33:31 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_cd(t_node **cmd)
{
	char	*path;
	char	*new_path;
	char	*path_env;

	path = NULL;
	new_path = NULL;
	path_env = NULL;
	if ((*cmd)->next)
	{
		/*
		 * ../../../....../../ 이것도 실행된다.
		 */
		(*cmd) = (*cmd)->next;
		new_path = ft_strdup((*cmd)->str);
		if (!ft_strcmp(new_path, "~"))
			path = ft_strdup(ft_getenv(g_info.envp, "HOME"));
		else
		{
			path = ft_strdup(ft_getenv(g_info.envp, "PWD"));
			ft_cd_exec(&path, new_path);
		}
		printf("path == %s\n", path);
		if (chdir(path) == -1)
		{
			ft_putstr("minishell: cd:");
			ft_putstr((*cmd)->str);
			perror(": ");
			g_info.exit_code = 1;
		}
		else
		{
			path_env = ft_strjoin("PWD=", path);
			printf("pp = %s\n", path);
			ft_update_env(g_info.envp, path_env, "PWD");
			free(path_env);
			g_info.exit_code = 0;
		}
	}
	free(path);
	free(new_path);
}
/////////////////////////////////////
//perror 함수 쓰기 erron 사용하기
//cd == home
//cd ..			../../pathdjwdjkd/dwqjdkwlq
//if chdir == -1 --> error message, exit_code
//cd .
//cd /path
//
//
//update pwd ==> ft_update_env(t_envp *envp, char *str, char *key);
//				ft_update_env(g_info.envp, (*cmd)->str, ft_key((*cmd)->str) ou key);
/////////////////////////////////////////
