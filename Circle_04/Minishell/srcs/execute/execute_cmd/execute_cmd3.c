/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:44:16 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/26 20:29:31 by hyungyoo         ###   ########.fr       */
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
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(": command not found\n", 2);
	ft_exit_minishell(127, &(cmd_start));
}

void	ft_error_no_path(char *str)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

void	ft_execmd(t_node *node, t_cmd *cmd_start)
{
	if (!ft_strcmp(node->str, ""))
		ft_error_message_execmd(cmd_start);
	//if (ft_getenv(g_info.envp, "PATH") == NULL)
	//	return (ft_error_no_path(node->str));
	if (ft_check_path_exec(node))
		ft_execmd_child(node);
	ft_exit_minishell(g_info.exit_code, &cmd_start);
}

char	*get_path(char *str)
{
	char	**split_path;
	int		i;
	char	*tmp1;
	char	*tmp2;

	i = -1;
	if (str[0] == '/')
		return (ft_strdup(str));
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
