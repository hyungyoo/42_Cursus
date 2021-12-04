/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:54:30 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/12/03 10:53:16 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_exec_new_path(char *old_path, char *path)
{
	char	*path_env;
	char	*old_pwd;

	path_env = ft_strjoin("PWD=", path);
	old_pwd = ft_strjoin("OLDPWD=", old_path);
	ft_update_path_oldpath(path_env, old_pwd);
	free(path_env);
	free(old_pwd);
}

void	ft_exec_path(char *new_path)
{
	char	*path;
	char	*old_path;

	if (g_info.flag_pwd == 1)
		old_path = ft_strdup("");
	else
		old_path = ft_strdup(ft_getenv(g_info.envp, "PWD"));
	if (ft_getenv(g_info.envp, "PWD"))
		path = ft_strdup(ft_getenv(g_info.envp, "PWD"));
	else
		path = NULL;
	if (!ft_strcmp(new_path, "/"))
		ft_exec_root_path(old_path);
	else if (ft_exec_dir(&path, new_path))
		ft_exec_new_path(old_path, path);
	free(path);
	free(old_path);
}

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
		if (cmd->next)
			cmd = cmd->next;
		else
			break ;
	}
	return (arg_count);
}

char	*ft_get_path(t_node *cmd)
{
	char	*ret;
	char	**array;

	ret = NULL;
	array = ft_array_double_export(cmd);
	ret = ft_strdup(array[0]);
	free_tab2(array);
	return (ret);
}

void	ft_cd(t_node **cmd)
{
	char	*new_path;

	if ((*cmd)->next && (*cmd)->next->type != PIPE)
	{
		(*cmd) = (*cmd)->next;
		new_path = ft_get_path(*cmd);
		if (!ft_strcmp(new_path, "~"))
			ft_exec_home("~");
		else if (!ft_strcmp(new_path, "-"))
			ft_exec_old_path();
		else
			ft_exec_path(new_path);
		free(new_path);
	}
	else
		ft_exec_home(NULL);
}
