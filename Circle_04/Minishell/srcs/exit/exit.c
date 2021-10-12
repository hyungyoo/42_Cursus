/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:15:44 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/12 13:10:37 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_env(void)
{
	int	i;

	i = 0;
	while (g_info.env[i])
	{
		free(g_info.env[i]);
		i++;
	}
	free(g_info.env);
}

/*
 * free g_valeur
 * env, split_str;
 */

void	ft_free_global(void)
{
	ft_free_env();
	ft_free_double(g_info.split_cmd);
}

void	ft_exit(void)
{
	rl_clear_history();
	ft_free_global();
	exit(1);
}
