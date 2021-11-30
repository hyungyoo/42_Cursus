/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:44:16 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/30 20:43:46 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_add_cmd_path(char **path, char *split_str)
{
	if (!ft_strcmp(split_str, "."))
		return ;
	else if (!ft_strcmp(split_str, ".."))
		ft_avant_path(path);
	else
		ft_ajouter_path(path, split_str);
}

char	*ft_get_relative_path(char *str)
{
	char	*ret;
	char	**split_str;
	int		i;

	i = 0;
	if (str[0] == '/')
		ret = ft_strdup("/");
	else
		ret = ft_strdup(ft_getenv(g_info.envp, "PWD"));
	split_str = ft_split(str, '/');
	while (split_str[i])
		ft_add_cmd_path(&ret, split_str[i++]);
	return (ret);
}

char	*ft_reset_cmd_path(char *str)
{
	char	*ret_path;

	ret_path = ft_get_relative_path(str);
	if (access(ret_path, F_OK || X_OK) == 0)
		return (ret_path);
	free(ret_path);
	return (ft_strdup(str));
}

char	*get_path(char *str)
{
	char	**split_path;
	int		i;
	char	*tmp1;
	char	*tmp2;

	i = -1;
	if (ft_is_slash(str))
		return (ft_reset_cmd_path(str));
	split_path = ft_split(ft_getenv(g_info.envp, "PATH"), ':');
	while (split_path[++i])
	{
		tmp1 = ft_strjoin(split_path[i], "/");
		tmp2 = ft_strjoin(tmp1, str);
		free(tmp1);
		if (access(tmp2, F_OK | X_OK) == 0)
		{
			free_tab2(split_path);
			return (tmp2);
		}
		free(tmp2);
	}
	free_tab2(split_path);
	return (ft_strdup(str));
}
