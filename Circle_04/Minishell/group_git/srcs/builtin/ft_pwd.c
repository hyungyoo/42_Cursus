/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:45:04 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/23 01:01:57 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_pwd(t_node **cmd)
{
	(void)cmd;
	ft_putstr(ft_getenv(g_info.envp, "PWD"));
	ft_putstr("\n");
	g_info.exit_code = 0;
}
