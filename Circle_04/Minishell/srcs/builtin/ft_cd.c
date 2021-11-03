/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:54:30 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/03 03:17:29 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_error_message_cd(char *new_path)
{
	if (new_path)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(new_path, 2);
		perror(" \b");
	}
	else
	{
		ft_putstr_fd("minishell: cd", 2);
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

static int	ft_is_slash(char *str)
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

int	ft_check_error(char **path, char *new_path)
{
	if (!new_path)
		return (0);
	if (new_path[0] == '/')
		return (ft_new_path(path, new_path));
	if (!path || !*path)
		return (0);
	return (1);
}

int	ft_exec_chdir(char **path, char *new_path, char *path_tmp,
		char **split_new_path)
{
	int	i;

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
	return (1);
}

int	ft_exec_dir(char **path, char *new_path)
{
	char	**split_new_path;
	char	*path_tmp;

	split_new_path = NULL;
	path_tmp = NULL;
	if (!(ft_check_error(path, new_path)))
		return (0);
	split_new_path = ft_split_cd(new_path);
	path_tmp = ft_strdup(*path);
	if (!(ft_exec_chdir(path, new_path, path_tmp, split_new_path)))
		return (0);
	free(path_tmp);
	free_tab2(split_new_path);
	return (1);
}

void	ft_exec_home(void)
{
	char	*path_env;
	char	*path;

	path_env = NULL;
	path = NULL;
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
		g_info.flag_pwd = 0;
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
		g_info.flag_pwd = 0;
	}
	free(path);
}

// cd one arg;
// pass until one

int	ft_num_arg_cd(t_node *cmd)
{
	t_node	*tmp;
	int		arg_count;

	arg_count = 0;
	tmp = cmd->prev;
	while (tmp != cmd)
	{
		if (cmd->type == ARG)
			arg_count++;
		cmd = cmd->next;
	}
	return (arg_count);
}

void	ft_cd(t_node **cmd)
{
	char	*new_path;

	new_path = NULL;
	if (ft_num_arg_cd(*cmd) > 1)
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		g_info.exit_code = 1;
		return ;
	}
	if ((*cmd)->next)
	{
		(*cmd) = (*cmd)->next;
		while ((*cmd) && (*cmd)->type != ARG)
			(*cmd) = (*cmd)->next;
		new_path = ft_strdup((*cmd)->str);
		if (!ft_strcmp(new_path, "~"))
			ft_exec_home();
		else
			ft_exec_path(new_path);
		free(new_path);
	}
	else
		ft_exec_home();
	g_info.exit_code = 0;
}
