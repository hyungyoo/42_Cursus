/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:44:01 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/21 01:46:30 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_error_message(char *path, char **argv, char **env)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": command not found\n", 2);
	free(path);
	free_tab2(argv);
	free_tab2(env);
	g_info.exit_code = 127;
	return (0);
}

int	ft_error_message_path(char *path, char **argv,
	char **env)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	free(path);
	free_tab2(argv);
	free_tab2(env);
	g_info.exit_code = 127;
	return (0);
}

int	ft_error_message_pwd(char *path, char **argv,
	char **env)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": is a directory\n", 2);
	free(path);
	free_tab2(argv);
	free_tab2(env);
	g_info.exit_code = 126;
	return (0);
}

int	ft_error_message_no_path(char **argv, char **env)
{
	if (!argv || !*argv)
		return (1);
	if (!ft_strncmp(argv[0], "/", 1))
		return (0);
	else if (!ft_getenv(g_info.envp, "PATH"))
	{
		ft_putstr_fd("Minishell: ", 2);
		ft_putstr_fd(argv[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		free_tab2(argv);
		free_tab2(env);
		g_info.exit_code = 127;
		return (1);
	}
	return (0);
}

void	ft_execmd_child(t_node *node)
{
	char	*path;
	char	**argv;
	char	**env;

	env = ft_array_double_env();
	argv = get_arg(node);
	path = get_path(argv[0]);
	execve(path, argv, env);
}
