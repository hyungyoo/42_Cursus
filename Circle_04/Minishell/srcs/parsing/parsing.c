/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:06:00 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/12 17:31:48 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* 
 *	1. ft_parsing_cmd : parsing cmd
 *	2. free all
 */
void	parsing(char *str)
{
	if (!str)
		return ;
	if (!ft_parsing_cmd(str))
		return ;
	/*
	to do:
		1. 
	*/
	int	i = 0;
	while (g_info.split_cmd[i])
	{
		printf("%s\n", g_info.split_cmd[i++]);
	}
}
