/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:54:30 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/26 16:55:45 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	execute_cd_with_root(char *new_path, char *path_tmp,
		char **split_new_path)
{
	if (chdir(new_path) == -1)
	{
		chdir(path_tmp);
		free(path_tmp);
		ft_error_message_cd(new_path);
		free_tab2(split_new_path);
		return (0);
	}
	return (1);
}

void	ft_exec_path(char *new_path)
{
	char	*path;
	char	*path_env;
	char	*old_pwd;
	char	*old_path;

	path_env = NULL;
	if (g_info.flag_pwd == 1)
		old_path = ft_strdup("");
	else
		old_path = ft_strdup(ft_getenv(g_info.envp, "PWD"));
	if (ft_getenv(g_info.envp, "PWD"))
		path = ft_strdup(ft_getenv(g_info.envp, "PWD"));
	else
		path = NULL;
	if (ft_exec_dir(&path, new_path))
	{
		path_env = ft_strjoin("PWD=", path);
		old_pwd = ft_strjoin("OLDPWD=", old_path);
		ft_update_path_oldpath(path_env, old_pwd);
	}
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

void	ft_cd(t_node **cmd)
{
	char	*new_path;

	if ((*cmd)->next && (*cmd)->next->type != PIPE)
	{
		(*cmd) = (*cmd)->next;
		while ((*cmd) && !ft_not_type((*cmd)) && (*cmd)->type != PIPE)
		{
			if ((*cmd)->next)
				(*cmd) = (*cmd)->next;
			else
				break ;
		}
		if (!(*cmd) || (*cmd)->type == PIPE || (*cmd)->type == FILE)
			return ;
		new_path = ft_strdup((*cmd)->str);
		if (!ft_strcmp(new_path, "~"))
			ft_exec_home();
		else
			ft_exec_path(new_path);
		free(new_path);
	}
	else
		ft_exec_home();
}
