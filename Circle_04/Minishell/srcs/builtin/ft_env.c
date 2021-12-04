/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 00:10:53 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/12/03 22:13:12 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_usleep(int i)
{
	int	j;
	int	tmp;

	tmp = 10000000 * i;
	j = 0;
	while (j < tmp)
		j++;
}

void	ft_update_last_env(char	*path)
{
	free(g_info.last_env_str);
	g_info.last_env_str = NULL;
	if (!ft_strcmp(path, "env"))
		g_info.last_env_str = ft_strjoin("_=", "/usr/bin/env");
	else
		g_info.last_env_str = ft_strjoin("_=", path);
}

void	ft_env(t_node **cmd)
{
	ft_update_last_env("env");
	if ((*cmd)->next && ft_not_type((*cmd)->next))
	{
		ft_putstr_fd("env: too many arguments\n", 2);
		g_info.exit_code = 1;
		return ;
	}
	ft_usleep(3);
	ft_print_env(g_info.envp);
	g_info.exit_code = 0;
}
