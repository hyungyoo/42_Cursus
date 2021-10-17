/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_list_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:46:59 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/17 16:47:36 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_key(char *env)
{
	char	*key;

	return (key);
}

char	*ft_value(char *env)
{
	char	*value;

	return (value);
}

t_envp	*ft_new_node(char *env)
{
	t_envp	*envp;

	envp = (t_envp *)malloc(sizeof(t_envp));
	if (!envp)
		return (NULL);
	envp->envp_str = ft_strdup(env);
	envp->envp_key = ft_key(env);
	envp->envp_value = ft_value(env);
	envp->next = envp;
	envp->prev = envp;
	return (envp);
}

static void	ft_ajouter_node(t_envp **envp_list, t_env *env)
{
	if (!envp || !env)
		return ;
	if (!*envp)
		return ;
	else
	{
		(*envp)->prev->next = env;
		env->prev = (*envp)->prev;
		(*envp)->prev = env;
		env->next = (*envp);
	}
}

void	ft_node_list_env(t_envp **envp_list, char **env)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		ft_aouter_node(env_list, ft_new_node(env[i]));
		i++;
	}
}
