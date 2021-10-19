/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:54:30 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/19 21:41:52 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_cd(t_node **cmd)
{
	char	*pwd;
	
	(void)cmd;
	pwd = getenv("PWD");

	printf("%s == pwd\n", pwd);
	char *new = ft_strjoin(pwd, "/Minishell");
	pwd = getenv(new);
	int	i = chdir(new);
	printf("%d, %s == pwd\n",i , pwd);
}
