/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:57:46 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/26 19:29:21 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	hanlder_child_pid(int signum)
{
	if (signum == SIGINT)
	{
		g_info.exit_code = 130;
		ft_putstr("\n");
	}
	else if (signum == SIGQUIT)
	{
		g_info.exit_code = 131;
		ft_putstr("Quit: 3\n");
	}
	g_info.pid_child = 0;
}

void	handler(int signum)
{
	if (g_info.pid_child != 0)
		hanlder_child_pid(signum);
	else if (signum == SIGINT || signum == SIGQUIT)
	{
		ft_putstr("\r");
		rl_on_new_line();
		rl_redisplay();
		ft_putstr("  \b\b");
		if (signum == SIGINT)
		{
			ft_putstr("\n");
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
	}
	return ;
}
