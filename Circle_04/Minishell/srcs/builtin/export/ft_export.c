/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:35:32 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/25 20:54:58 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_is_lettre(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

char	*ft_ajouter_value(char *str)
{
	int		i;
	int		size_value;
	char	*ret;

	if (!str)
		return (NULL);
	ret = NULL;
	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	size_value = ft_strlen(str) - i;
	if (!size_value)
		return (ft_strdup(""));
	ret = (char *)malloc(sizeof(char) * size_value + 1);
	ft_strlcpy(ret, str + i + 1, size_value + 1);
	return (ret);
}

void	ft_update_env(t_envp *envp, char *str, char *key)
{
	if (ft_getenv(g_info.envp, key))
	{
		while (envp)
		{
			if (!ft_strcmp((envp)->envp_key, key))
			{
				free((envp)->envp_value);
				envp->envp_value = NULL;
				(envp)->envp_value = ft_ajouter_value(str);
				free((envp)->envp_str);
				envp->envp_str = NULL;
				(envp)->envp_str = ft_strdup(str);
				return ;
			}
			envp = (envp)->next;
		}
	}
	else
		ft_ajouter_node(&envp, ft_new_node_env(str));
}

int	ft_size_node(t_envp *envp)
{
	int		ret;
	t_envp	*tmp;

	ret = 0;
	if (!envp)
		return (-1);
	tmp = envp->prev;
	while (envp != tmp)
	{
		ret++;
		envp = envp->next;
	}
	return (ret + 1);
}

char	**ft_array_double_env(void)
{
	t_envp	*envp;
	char	**array_env;
	int		i;

	i = 0;
	envp = NULL;
	envp = g_info.envp;
	if (!envp)
		return (NULL);
	array_env = (char **)malloc(sizeof(char *) * (ft_size_node(envp) + 1));
	if (!array_env)
		return (NULL);
	while (i < ft_size_node(envp))
	{
		array_env[i] = ft_strdup(envp->envp_str);
		if (envp->next)
		{
			envp = envp->next;
			i++;
		}
	}
	array_env[i] = NULL;
	return (array_env);
}
