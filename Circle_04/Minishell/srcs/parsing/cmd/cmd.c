/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:26:07 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/08 09:36:13 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_parsing_cmd(char *str)
{
	char *cmd;

	return (cmd);
}

char	**ft_parsing_cmd_option(char *str)
{
	char **cmd_parsing;

	return (cmd_parsing);
}

char	**ft_parsing_arg(char *str)
{
	char**arg;

	return (arg);
}

t_parsing	*ft_newnode(char *str)
{
	t_parsing *parsing;
	
	to do:
		1. malloc
		2. parsing->cmd = ft_pasing_cmd(str);
		2. parsing->cmd_option = ft_pasing_cmd_option(str);
		2. parsing->arg = ft_pasing_arg(str);
		3. parsing->next = parsing;
		4. parsing->prev = parsing;

	return (parsing);
}

void	ft_parsing_cmd(char *str)
{
	(void)str;
	/*
	to do:
		1. create node;
		2. dans la function, cmd, arg etc;

		//////////autre fichier
		3. link node (double)
		4. ajouter global pour ft_exit free
	*/
	return ;
}

