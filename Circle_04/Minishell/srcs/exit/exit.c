/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:15:44 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/08 08:25:56 by hyungyoo         ###   ########.fr       */
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

void	ft_free_global(void)
{
	ft_free_env();
}

void	ft_exit(void)
{
	rl_clear_history();
	ft_free_global();
	exit(1);
}
