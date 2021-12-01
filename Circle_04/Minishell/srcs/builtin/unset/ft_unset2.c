/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 02:10:13 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/12/01 22:25:52 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_unset(t_node **cmd)
{
	g_info.exit_code = 0;
	if (!cmd || !(*cmd))
		return ;
	if ((*cmd)->flag_emptystr)
	{
		g_info.exit_code = 1;
		empty_error_message("unset");
	}
	if (!((*cmd)->next))
		return ;
	else if ((*cmd)->next->type == PIPE)
		return ;
	if (!ft_strcmp((*cmd)->next->str, "PWD"))
		g_info.flag_pwd = 1;
	else
		ft_unset_exec(cmd);
}
