/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:41:48 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/25 18:35:10 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	check_dleft_error(t_node **node)
{	
	if (!(*node)->next)
	{
		ft_putstr_fd("minishell: parse error near\n", 2);
		return (0);
	}	
	(*node) = (*node)->next;
	if (check_redir(*node))
	{
		ft_putstr_fd("minisehll: syntax error near unexpected token `<<'\n", 2);
		return (0);
	}
	return (1);
}
