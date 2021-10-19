/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 02:10:13 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/19 18:17:50 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_chercher_key(t_envp *envp, char *arg)
{
	if (!envp || !arg)
		return (0);
	envp->prev->next = NULL;
	while (envp)
	{
		if (!ft_strcmp(envp->envp_key, arg))
			return (1);
		envp = envp->next;
	}
	return (0);
}

void	ft_free_one_node(t_envp **envp, char *arg)
{
	(*envp)->prev->next = NULL;
	while (*envp)
	{
		if (!ft_strcmp((*envp)->envp_key, arg))
		{
			printf("here\n");
			//(*envp)->prev->next = (*envp)->next;
			//(*envp)->next->prev = (*envp)->prev;
			/*
			free((*envp)->envp_key);
			free((*envp)->envp_value);
			free((*envp)->envp_str);
			free((*envp));
			*/
		}
		(*envp) = (*envp)->next;
	}
}

void	ft_unset(t_node **cmd)
{
	char	*arg;

	if (!cmd || !*cmd)
		return ;
	if ((*cmd)->next->type != 12)
		return ;
	arg = (*cmd)->next->str;
	if (!ft_chercher_key(g_info.envp, arg))
		return ;
	ft_free_one_node(&(g_info.envp), arg);
}

///il faut refaire pour unset
// pas besoin de ft_chercher;;;;
