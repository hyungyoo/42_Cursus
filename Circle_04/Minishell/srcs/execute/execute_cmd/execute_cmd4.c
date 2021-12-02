/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:44:16 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/12/02 16:39:14 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_check_path_exec(t_node *node)
{
	char	*path;
	char	**argv;
	char	**env;
	int		flag_access;

	path = NULL;
	env = ft_array_double_env();
	argv = get_arg(node);
	if (ft_error_message_no_path(argv, env))
		return (0);
	if (argv[0])
		path = get_path(argv[0]);
	flag_access = access(path, F_OK | X_OK);
	if (!ft_strcmp(ft_getenv(g_info.envp, "PWD"), path))
		return (ft_error_message_pwd(path, argv, env));
	else if (ft_getenv(g_info.envp, "PATH")
		&& !ft_strcmp(ft_getenv(g_info.envp, "PATH"), path))
		return (ft_error_message_path(path, argv, env));
	else if (flag_access == -1)
		return (ft_error_message(path, argv, env));
	free_tab2(argv);
	free_tab2(env);
	free(path);
	return (1);
}

void	ft_error_message_execmd(t_cmd *cmd_start)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(": command not found\n", 2);
	ft_exit_minishell(127, &(cmd_start));
}

void	ft_error_no_path(char *str)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

/*
	//if (ft_getenv(g_info.envp, "PATH") == NULL)
	//	return (ft_error_no_path(node->str));
*/

void	execmd_error_check(t_node *node, t_cmd *cmd_start)
{	
	if (!ft_strcmp(node->str, "/") && node->flag_nospace == 0)
	{
		ft_putstr_fd("minishell: /: is a directory\n", 2);
		ft_exit_minishell(126, &cmd_start);
	}
	else if (!ft_strcmp(node->str, ".") && node->flag_nospace == 0)
	{
		ft_putstr_fd("minishell: .: filename argument required\n", 2);
		ft_putstr_fd(".: usage: . filename [arguments]\n", 2);
		ft_exit_minishell(2, &cmd_start);
	}
	else if (!ft_strcmp(node->str, "..") && node->flag_nospace == 0)
	{
		ft_putstr_fd("minishell: ..: command not found\n", 2);
		ft_exit_minishell(127, &cmd_start);
	}
	if (ft_getenv(g_info.envp, "HOME"))
	{
		if (!ft_strcmp(node->str, ft_getenv(g_info.envp, "HOME"))
			&& node->flag_nospace == 0)
		{	
			ft_putstr_fd("minishell: /Users/hyungyoo: is a directory\n", 2);
			ft_exit_minishell(126, &cmd_start);
		}
	}
}

void	ft_execmd(t_node *node, t_cmd *cmd_start)
{
	if (!ft_strcmp(node->str, ""))
		ft_error_message_execmd(cmd_start);
	execmd_error_check(node, cmd_start);
	if (ft_check_path_exec(node))
		ft_execmd_child(node);
	ft_exit_minishell(g_info.exit_code, &cmd_start);
}
