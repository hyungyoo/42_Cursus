/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:44:33 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/09/30 17:46:21 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	copy_env(char **env)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (env[count])
		count++;
	g_info.env = (char **)malloc(sizeof(char *) * (count + 1));
	if (!(g_info.env))
		return ;
	while (env[i])
	{
		g_info.env[i] = ft_strdup(env[i]);
		i++;
	}
	g_info.env[i] = NULL;
}

void	ft_initial_g(void)
{
	g_info.env = NULL;
	g_info.quit_quote = 0;
}

void	ft_initial(char **env)
{
	ft_initial_g();
	copy_env(env);
}
