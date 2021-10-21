/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:45:04 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/19 19:35:44 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_pwd(t_node **cmd)
{
	char	*pwd;

	if ((*cmd)->next && (*cmd)->next->type == 12)
	{
		ft_putstr("pwd : too many arguments\n");
		g_info.exit_code = 1;
		return ;
	}
	pwd = NULL;
	pwd = getenv("PWD");
	ft_putstr(pwd);
	ft_putstr("\n");
	g_info.exit_code = 0;
}
