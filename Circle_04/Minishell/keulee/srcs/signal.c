/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:57:46 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/22 15:57:47 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handler(int signum)
{
	if (signum == SIGINT || signum == SIGQUIT)
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
