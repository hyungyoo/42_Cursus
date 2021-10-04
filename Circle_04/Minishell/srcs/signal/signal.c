/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 00:26:27 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/04 17:39:35 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handler(int signum)
{
	if (signum == SIGINT || signum == SIGQUIT)
	{
		printf("\r");
		rl_on_new_line();
		rl_redisplay();
		printf("  \b\b");
		if (signum == SIGINT)
		{
			printf("\n");
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
	}
	return ;
}
