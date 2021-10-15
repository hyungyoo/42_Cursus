/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:45:04 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/15 17:03:54 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_pwd(t_node **cmd)
{
	char	*pwd;

	(void)cmd;
	pwd = NULL;
	pwd = getenv("PWD");
	ft_putstr(pwd);
	ft_putstr("\n");

}
