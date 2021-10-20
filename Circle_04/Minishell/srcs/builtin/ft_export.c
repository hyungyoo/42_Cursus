/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:35:32 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/20 14:58:09 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_check_egal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_ajouter_value(char *str)
{
	int		i;
	int		size_value;
	char	*ret;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	size_value = ft_strlen(str) - i;
	ret = (char *)malloc(sizeof(char) * size_value);
	ft_strlcpy(ret, str + i + 1, size_value);
	return (ret);
}

void	ft_update_env(t_envp *envp, char *str, char *key)
{
	while (envp)
	{
		if (!ft_strcmp((envp)->envp_key, key))
		{
			free((envp)->envp_value);
			(envp)->envp_value = ft_ajouter_value(str);
			free((envp)->envp_str);
			(envp)->envp_str = ft_strdup(str);
			return ;
		}
		envp = (envp)->next;
	}
}

void	ft_export(t_node **cmd)
{
	char	*str;
	char	*key_tmp;
	t_envp	*new;

	if (!cmd || !(*cmd))
		return ;
	if (!((*cmd)->next))
		return ;
	str = (*cmd)->next->str;
	if (!ft_check_egal(str))
		return ;
	key_tmp = ft_key(str);
	if (ft_getenv(g_info.envp, key_tmp))
		ft_update_env(g_info.envp, str, key_tmp);
	else
	{
		new = ft_new_node_env(str);
		ft_ajouter_node(&(g_info.envp), new);
	}
	free(key_tmp);
}
