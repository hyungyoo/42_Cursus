/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_list_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:46:59 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/19 17:48:46 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_size_key(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (0);
}

char	*ft_key(char *env)
{
	char	*key;
	int		size_key;

	size_key = ft_size_key(env);
	key = (char *)malloc(sizeof(char) * size_key + 1);
	ft_strlcpy(key, env, size_key + 1);
	return (key);
}

char	*ft_value(char *key)
{
	char	*value;

	if (!getenv(key))
		return (NULL);
	else
		value = ft_strdup(getenv(key));
	return (value);
}

t_envp	*ft_new_node_env(char *env)
{
	t_envp	*envp;

	envp = (t_envp *)malloc(sizeof(t_envp));
	if (!envp)
		return (NULL);
	envp->envp_str = ft_strdup(env);
	envp->envp_key = ft_key(env);
	envp->envp_value = ft_value(envp->envp_key);
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

void	ft_node_list_env(t_envp **envp_list, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		ft_ajouter_node(envp_list, ft_new_node_env(env[i]));
		i++;
	}
}

void	ft_print_env(t_envp *envp)
{
	if (!envp)
		return ;

	envp->prev->next = NULL;
	while (envp)
	{
		ft_putstr(envp->envp_str);
		ft_putstr("\n");
		envp = envp->next;
	}
}
