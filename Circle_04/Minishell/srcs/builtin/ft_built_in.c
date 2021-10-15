/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:31:21 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/15 17:07:50 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//void	ft_pass_arg(t_node **cmd);
//to do:
//	1. passe arg until next pipe ou redir
//	2. and check il y a arg?

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
