/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 02:10:13 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/19 02:25:51 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_chercher_key(t_envp *env, char *arg)
{
	env->prev->next = NULL;
	while (env)
	{
		if (!ft_strcmp(env->envp_key, arg))
			return (1);
		env = env->next;
	}
	return (0);
}

void	ft_unset(t_node **cmd)
{
	char	*arg;

	if (!cmd || !*cmd)
		return ;
	arg = (*cmd)->next->str;
	if (!ft_chercher_key(g_info.envp, arg))
		return ;

}

///il faut refaire pour unset
// pas besoin de ft_chercher;;;;
