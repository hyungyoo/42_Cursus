/* ************************************************************************** */
/*                                                                            *//*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 00:43:19 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/19 01:51:15 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_check_egal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	ft_export(t_node **cmd)
{
	char	*str;

	if (!cmd || !(*cmd))
		return ;
	if (!((*cmd)->next))
		return ;
	str = (*cmd)->next->str;
	if (!ft_check_egal(str))
		return ;
	ft_ajouter_node(&(g_info.envp), ft_new_node_env(str));


	// retard pour afficher env

	// pas de value! et free for malloc

	//malloc --> strdup
	//et free


	// hell=ok
	// hell no '\n'
	// hellhell= jdlwq --> ' '
	// hellhell =djlkwq --> error message
}
