/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:41:48 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/12/03 11:46:51 by hyungyoo         ###   ########.fr       */
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

void	ft_error_message_home(t_cmd *cmd_start)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(g_info.home, 2);
	ft_putstr_fd(" is a directory\n", 2);
	ft_exit_minishell(126, &cmd_start);
}
