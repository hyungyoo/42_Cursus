/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:15:44 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/13 16:08:37 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
 * free g_valeur
 * env, split_str;
 */
void	ft_exit(void)
{
	ft_free_all_node(&(g_info.parsing));
	rl_clear_history();
	exit(1);
}
