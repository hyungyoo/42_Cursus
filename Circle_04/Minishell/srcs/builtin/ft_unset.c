/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 02:10:13 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/19 19:34:16 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_chercher_key(t_envp *envp, char *arg)
{
	t_envp	*tmp;

	if (!envp || !arg)
		return (0);
	tmp = envp->prev;
	while (envp != tmp)
	{
		if (!ft_strcmp(envp->envp_key, arg))
			return (1);
		envp = envp->next;
	}
	if (!ft_strcmp(envp->envp_key, arg))
		return (1);
	return (0);
}

void	ft_free_one_node(t_envp *envp, char *arg)
{
	while (envp)
	{
		if (!ft_strcmp((envp)->envp_key, arg))
		{
			(envp)->next->prev = (envp)->prev;
			(envp)->prev->next = (envp)->next;
			free((envp)->envp_key);
			free((envp)->envp_value);
			free((envp)->envp_str);
			free((envp));
			return ;
		}
		(envp) = (envp)->next;
	}
}

void	ft_unset(t_node **cmd)
{
	char	*arg;

	if (!cmd || !(*cmd))
		return ;
	if (!((*cmd)->next))
	{
		ft_putstr("unset : not enough arguments\n");
		g_info.exit_code = 1;
		return ;
	}
	if ((*cmd)->next->type != 12)
	{
		ft_putstr("unset : not enough arguments\n");
		g_info.exit_code = 1;
		return ;
	}
	arg = (*cmd)->next->str;
	if (!ft_chercher_key(g_info.envp, arg))
		return ;
	ft_free_one_node(g_info.envp, arg);
	g_info.exit_code = 0;
}
