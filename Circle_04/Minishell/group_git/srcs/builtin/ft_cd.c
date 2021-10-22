/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:54:30 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/22 18:31:39 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_cd(t_node **cmd)
{
	char	*path;
	char	*new_path;

	path = NULL;
	new_path = NULL;
	path = ft_strdup(ft_getenv(g_info.envp, "PWD"));
	if ((*cmd)->next)
	{
		(*cmd) = (*cmd)->next;
		new_path = ft_strdup((*cmd)->str);
		if (!ft_strcmp(new_path, "~"))
		{
			chdir(ft_getenv(g_info.envp, "HOME"));
			// update pwd
			// if no pwd --> create pwd
			// or update pwd
		}
	}
	free(path);
	free(new_path);
}
		/*
		else if (!ft_strcmp(new_path, ".."))
			printf(".. est new_path\n");
		else if (!ft_strcmp(new_path, "."))
			return ;
		else
			chdir("/Users/hyungyoo/minishell_group/keulee");
	//////////////////////////////////////////
		printf("new path == %s\n", new_path);
	////////////////////////////////////////////
	}
	//////////////////////////////////////////
	printf("node pwd == %s\n", pwd_debut);
	////////////////////////////////////////
	if ((*cmd)->next)
		while ((*cmd)->next && (*cmd)->next->type != PIPE)
			(*cmd) = (*cmd)->next;
	
	free(pwd_debut);
	free(new_path);
/////////////////////////////////////
//perror 함수 쓰기 erron 사용하기
//cd == home
//cd ..			../../pathdjwdjkd/dwqjdkwlq
//if chdir == -1 --> error message, exit_code
//cd .
//cd /path
//
//
//update pwd ==> ft_update_env(t_envp *envp, char *str, char *key);
//				ft_update_env(g_info.envp, (*cmd)->str, ft_key((*cmd)->str) ou key);
/////////////////////////////////////////
}
*/
