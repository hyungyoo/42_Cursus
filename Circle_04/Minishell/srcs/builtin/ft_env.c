/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 00:10:53 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/19 00:41:24 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_env(t_node **cmd)
{
	if ((*cmd)->next && (*cmd)->next->type == 12)
	{
		ft_putstr("env: too many arguments\n");
		g_info.exit_code = 1;
		return ;
	}
	ft_print_env(g_info.envp);
	g_info.exit_code = 0;
}
