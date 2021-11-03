/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 02:10:13 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/03 03:08:27 by hyungyoo         ###   ########.fr       */
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

void	ft_unset_exec(t_node **cmd)
{
	(*cmd) = (*cmd)->next;
	while ((*cmd) && (*cmd)->type != PIPE)
	{
		if ((*cmd)->type == ARG)
		{
			if ((*cmd)->type == DOLR && (*cmd)->flag_nospace == 1)
				(*cmd) = (*cmd)->next;
			else if (ft_chercher_key(g_info.envp, (*cmd)->str))
				ft_free_one_node(g_info.envp, (*cmd)->str);
			g_info.exit_code = 0;
		}
		if ((*cmd)->next)
			(*cmd) = (*cmd)->next;
		else
			return ;
	}
}

void	ft_unset(t_node **cmd)
{
	if (!cmd || !(*cmd))
		return ;
	else if (!((*cmd)->next))
		return ;
	else if ((*cmd)->next->type == PIPE)
		return ;
	if (!ft_strcmp((*cmd)->next->str, "PWD"))
		g_info.flag_pwd = 1;
	else
		ft_unset_exec(cmd);
	g_info.exit_code = 0;
}
