/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:45:04 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/28 01:19:38 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_getenv_pwd(void)
{
	t_envp	*envp;
	t_envp	*tmp;
	char	*value_pwd;

	value_pwd = NULL;
	envp = NULL;
	envp = g_info.envp;
	tmp = envp->prev;
	while (envp != tmp)
	{
		if (!ft_strcmp(envp->envp_key, "PWD"))
			return (envp->envp_value);
		envp = envp->next;
	}
	if (!ft_strcmp(envp->envp_key, "PWD"))
		return (envp->envp_value);
	return (NULL);
}

void	ft_pwd(t_node **cmd)
{
	(void)cmd;
	ft_putstr(ft_getenv_pwd());
	ft_putstr("\n");
	g_info.exit_code = 0;
}
