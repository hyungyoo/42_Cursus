/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_list_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:46:59 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/18 12:08:00 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_node_list_env(t_envp **envp_list, char **env)
{
	int	i;
	int	last_env;

	last_env = ft_env_len(env) - 1;
	i = 0;
	while (i < last_env)
	{
		ft_ajouter_node(envp_list, ft_new_node_env(env[i]));
		i++;
	}
	g_info.last_env_str = ft_strdup(env[last_env]);
}

void	ft_print_env(t_envp *envp)
{
	t_envp	*tmp;

	if (!envp)
		return ;
	tmp = envp->prev;
	while (envp != tmp)
	{
		if (!(g_info.flag_pwd == 1 && !ft_strcmp(envp->envp_key, "PWD")))
		{
			ft_putstr(envp->envp_str);
			ft_putstr("\n");
		}
		envp = envp->next;
	}
	if (!(g_info.flag_pwd == 1 && !ft_strcmp(envp->envp_key, "PWD")))
	{
		ft_putstr(envp->envp_str);
		ft_putstr("\n");
	}
	ft_putstr(g_info.last_env_str);
	ft_putstr("\n");
}
