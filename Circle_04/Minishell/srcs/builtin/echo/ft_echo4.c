/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 02:26:25 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/18 18:00:02 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	check_pwd(t_node **cmd)
{
	if (!ft_strcmp((*cmd)->str, ft_getenv(g_info.envp, "PWD"))
		&& g_info.flag_pwd == 1)
		return (1);
	return (0);
}
