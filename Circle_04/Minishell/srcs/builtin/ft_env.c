/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 00:10:53 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/03 03:06:00 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_update_last_env(char	*path)
{
	free(g_info.last_env_str);
	g_info.last_env_str = NULL;
	g_info.last_env_str = ft_strjoin("_=", path);
}

void	ft_env(t_node **cmd)
{
	ft_update_last_env("env");
	if ((*cmd)->next && (*cmd)->next->type == ARG)
	{
		ft_putstr_fd("env: too many arguments\n", 2);
		g_info.exit_code = 1;
		return ;
	}
	ft_print_env(g_info.envp);
	g_info.exit_code = 0;
}
