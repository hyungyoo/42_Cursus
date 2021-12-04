/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:42:09 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/12/03 09:39:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_env(t_envp *envp)
{
	t_envp	*tmp;

	if (!envp)
		return ;
	envp->prev->next = NULL;
	while (envp)
	{
		tmp = envp->next;
		free(envp->envp_str);
		free(envp->envp_key);
		free(envp->envp_value);
		free(envp);
		envp = tmp;
	}
	free(envp);
	free(g_info.last_env_str);
}

void	ft_exit(int exit_code)
{
	ft_free_env(g_info.envp);
	rl_clear_history();
	exit(exit_code);
}

void	reset_pid(void)
{
	int	i;

	i = 0;
	while (i < PID_MAX_LIMIT)
		g_info.pid_pipe_child[i++] = 0;
	g_info.pid_child = 0;
}

void	ft_exit_minishell(int exit_code, t_cmd **cmd)
{
	ft_free_env(g_info.envp);
	free(g_info.home);
	g_info.home = NULL;
	free_list(cmd);
	rl_clear_history();
	exit(exit_code);
}
