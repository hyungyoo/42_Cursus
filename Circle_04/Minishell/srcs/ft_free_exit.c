/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:04:16 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/22 16:04:34 by hyungyoo         ###   ########.fr       */
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
	free(g_info.last_env_str);
}

void	ft_exit(int exit_code)
{
	ft_free_env(g_info.envp);
	rl_clear_history();
	exit(exit_code);
}

void	ft_exit_minishell(int exit_code, t_cmd **cmd)
{
	ft_free_env(g_info.envp);
	free_list(cmd);
	rl_clear_history();
	exit(exit_code);
}
