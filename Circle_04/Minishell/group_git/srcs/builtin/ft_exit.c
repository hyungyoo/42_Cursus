/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:00:19 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/20 15:18:07 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_exit_builtin(t_node **cmd)
{
	if (!cmd || !*cmd)
		return ;
	if (!ft_strcmp((*cmd)->str, "exit"))
	{
		ft_putendl_fd("\033[38;5;31mminishell exit \033[0m", 1);
		ft_exit(1);
	}
}
