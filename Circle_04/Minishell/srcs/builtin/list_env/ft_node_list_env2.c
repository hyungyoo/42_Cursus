/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_list_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:46:59 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/18 12:07:47 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_key(char *env)
{
	char	*key;
	int		size_key;

	key = NULL;
	size_key = ft_size_key(env);
	key = (char *)malloc(sizeof(char) * size_key + 1);
	ft_strlcpy(key, env, size_key + 1);
	return (key);
}

char	*ft_value(char *str)
{
	char	*value;

	value = NULL;
	value = ft_ajouter_value(str);
	return (value);
}

t_envp	*ft_new_node_env(char *env)
{
	t_envp	*envp;

	envp = NULL;
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

void	ft_ajouter_node(t_envp **envp, t_envp *new)
{
	if (!envp || !new)
		return ;
	if (!*envp)
		*envp = new;
	else
	{
		(*envp)->prev->next = new;
		new->prev = (*envp)->prev;
		(*envp)->prev = new;
		new->next = (*envp);
	}
}

int	ft_env_len(char **env)
{
	int	ret;

	ret = 0;
	while (env[ret])
		ret++;
	return (ret);
}
