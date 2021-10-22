/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:54:30 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/22 16:20:53 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_cd(t_node **cmd)
{
	char	*pwd_debut;
	char	*new_path;

	pwd_debut = ft_strdup(ft_getenv(g_info.envp, "PWD"));
	if ((*cmd)->next)
	{
		(*cmd) = (*cmd)->next;
		new_path = (*cmd)->str;
		printf("new path == %s\n", new_path);
	}
	printf("node pwd == %s\n", pwd_debut);

	if ((*cmd)->next)
		while ((*cmd)->next && (*cmd)->next->type != PIPE)
			(*cmd) = (*cmd)->next;

	/*
	 * pwd_debut 에서 
	 * new_path가 .또는 ..로 시작한다면, 합치기
	 * new_path가 /로 시작된다면 이미있던거 free하고 새로운경로로 지정
	 *
	 *
	 * env PATH 병경하기 
	 */
	/*
	char	*pwd;
	
	(void)cmd;
	pwd = getenv("PWD");

	printf("%s == pwd\n", pwd);
	char new[100] = "/Users/hyungyoo/42_Cursus";
	int	i = chdir(new);
	pwd = ft_getenv(g_info.envp, "haha");
	printf("%d, %s == pwd\n",i , getenv("PWD"));
	*/
}
