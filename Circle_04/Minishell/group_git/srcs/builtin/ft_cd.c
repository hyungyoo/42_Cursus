/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:54:30 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/23 17:14:00 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_error_message_cd(char *new_path)
{
	ft_putstr("minishell: cd:");
	ft_putstr(new_path);
	perror(": ");
	g_info.exit_code = 1;
}

int	ft_exec_dir(char **path, char *new_path)
{
	char	**split_new_path;
	int		i;
	char	*path_tmp;

	if (new_path[0] == '/')
	{
		free(*path);
		*path = ft_strdup(new_path);
		chdir(*path);
		return (1);
	}
	split_new_path = ft_split(new_path, '/');
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
	free_tab2(split_new_path);
	return (1);
}

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
		(*cmd) = (*cmd)->next;
		new_path = ft_strdup((*cmd)->str);
		if (!ft_strcmp((*cmd)->str, "~"))
		{
			path = ft_strdup(ft_getenv(g_info.envp, "HOME"));
			if (chdir(path) == -1)
			{
				ft_error_message_cd(path);
				g_info.exit_code = 1;
			}
			else
			{
				path_env = ft_strjoin("PWD=", path);
				ft_update_env(g_info.envp, path_env, "PWD");
				free(path_env);
				g_info.exit_code = 0;
			}
		}
		else if (ft_strcmp((*cmd)->str, "~"))
		{
			path = ft_strdup(ft_getenv(g_info.envp, "PWD"));
			if (ft_exec_dir(&path, new_path))
			{
				path_env = ft_strjoin("PWD=", path);
				ft_update_env(g_info.envp, path_env, "PWD");
				free(path_env);
				g_info.exit_code = 0;
			}
		}
		printf("path == %s\n", path);
	}
	free(path);
	free(new_path);
}
/* home 
if (!ft_strcmp((*cmd)->str, "~"))
		{
			path = ft_strdup(ft_getenv(g_info.envp, "HOME"));
			if (chdir(path) == -1)
			{
				ft_error_message_cd(path);
				g_info.exit_code = 1;
			}
			else
			{
				path_env = ft_strjoin("PWD=", path);
				ft_update_env(g_info.envp, path_env, "PWD");
				free(path_env);
				g_info.exit_code = 0;
			}
		}
	}
 * 하나씩 실행하면서, cd함수에서
 * 스플릿을 한후에, 그 다음에 하나씩넣어서 해본다.
 * 만약에 오류가난다면, 저장해둔 원레 pwd로 이동
 */
