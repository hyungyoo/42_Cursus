/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:31:21 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/19 20:55:49 by hyungyoo         ###   ########.fr       */
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
		ft_echo(cmd);
	else if (!ft_strcmp((*cmd)->str, "pwd"))
		ft_pwd(cmd);
	else if (!ft_strcmp((*cmd)->str, "cd"))
		ft_cd(cmd);
	else if (!ft_strcmp((*cmd)->str, "export"))
		ft_export(cmd);
	else if (!ft_strcmp((*cmd)->str, "unset"))
		ft_unset(cmd);
	else if (!ft_strcmp((*cmd)->str, "env"))
		ft_env(cmd);
}
//passe all arg
