/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:15:44 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/12 13:44:12 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
 * free g_valeur
 * env, split_str;
 */
void	ft_free_global(void)
{
	if (!g_info.env)
		ft_free_double(g_info.env);
	if (!g_info.split_cmd)
		ft_free_double(g_info.split_cmd);
}

void	ft_exit(void)
{
	rl_clear_history();
	ft_free_global();
	exit(1);
}
