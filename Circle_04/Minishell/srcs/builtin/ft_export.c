/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:35:32 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/19 22:46:57 by hyungyoo         ###   ########.fr       */
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

void	ft_update_env(char *str, char *key)
{
	while (g_info.envp)
	{
		if (!ft_strcmp((g_info.envp)->envp_key, key))
		{
			free((g_info.envp)->envp_value);
			(g_info.envp)->envp_value = ft_ajouter_value(str);
			return ;
		}
		g_info.envp = (g_info.envp)->next;
	}
	// 이쪽으로 들어오면, 겹쳤던 키가있는 str이 맨뒤로 올라감
	// 그리고 세그폴트
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
		printf("hello\n");
		//ft_update_env(str, key_tmp);
	else
	{
		new = ft_new_node_env(str);
		new->envp_value = ft_ajouter_value(str);
		ft_ajouter_node(&(g_info.envp), new);
	}
	free(key_tmp);
}
