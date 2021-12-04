/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:49:22 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/12/03 09:38:56 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	copy_env(char **env)
{
	t_envp	*envp;

	envp = NULL;
	ft_node_list_env(&envp, env);
	g_info.envp = envp;
}

void	ft_initial_g(void)
{
	g_info.envp = NULL;
	g_info.pid_child = 0;
	g_info.flag_pwd = 0;
	g_info.home = ft_strdup(getenv("HOME"));
	g_info.last_env_str = NULL;
}

void	ft_initial(char **env, int ac, char **av)
{
	(void)ac;
	(void)av;
	ft_initial_g();
	copy_env(env);
}
