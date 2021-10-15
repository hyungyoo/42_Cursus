/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:31:21 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/15 16:44:09 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_built_in(t_node	**cmd)
{
	if (!ft_strcmp((*cmd)->str, "echo"))
		printf("i am echo\n");
	else if (!ft_strcmp((*cmd)->str, "pwd"))
		ft_pwd(cmd);
	else if (!ft_strcmp((*cmd)->str, "cd"))
		printf("i am cd\n");
	else if (!ft_strcmp((*cmd)->str, "export"))
		printf("i am export\n");
	else if (!ft_strcmp((*cmd)->str, "unset"))
		printf("i am unset\n");
	else if (!ft_strcmp((*cmd)->str, "env"))
		printf("env\n");
}
