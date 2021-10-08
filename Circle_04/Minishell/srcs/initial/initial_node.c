/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:09:55 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/08 17:10:53 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_init_node(t_parsing *parsing)
{
	parsing->cmd = NULL;
	parsing->cmd_option = NULL;
	parsing->arg = NULL;
	parsing->next_multi_cmd = NULL;
	parsing->next = NULL;
	parsing->prev = NULL;
}
