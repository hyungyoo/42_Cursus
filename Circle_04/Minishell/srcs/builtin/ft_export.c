/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:35:32 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/27 10:56:17 by hyungyoo         ###   ########.fr       */
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

	if (!str)
		return (NULL);
	ret = NULL;
	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	size_value = ft_strlen(str) - i;
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

int	ft_tab_size(char **str)
{
	int	ret;

	ret = 0;
	while (str[ret])
		ret++;
	return (ret);
}

void	ft_sort_env(char **env_sort)
{
	int		i;
	int		j;
	int		size_array;
	char	*tmp;

	tmp = NULL;
	i = 0;
	size_array = ft_tab_size(env_sort);
	while (i < size_array - 1)
	{
		j = i + 1;
		while (j < size_array)
		{
			if (ft_strcmp(env_sort[i], env_sort[j]) > 0)
			{
				tmp = env_sort[i];
				env_sort[i] = env_sort[j];
				env_sort[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	ft_export_env(void)
{
	char	**env_sort;
	int		i;

	i = 0;
	env_sort = ft_array_double_env();
	ft_sort_env(env_sort);
	while (env_sort[i])
	{
		ft_putstr("declare -x ");
		ft_putstr(env_sort[i]);
		ft_putstr("\n");
		i++;
	}
	free_tab2(env_sort);
}

void	ft_export(t_node **cmd)
{
	char	*key_tmp;

	if (!cmd || !(*cmd) || !(*cmd)->next)
	{
		if (!(*cmd)->next)
			ft_export_env();
		return ;
	}
	(*cmd) = (*cmd)->next;
	while (*cmd && (*cmd)->type == 12)
	{
		if (ft_check_egal((*cmd)->str))
		{
			key_tmp = ft_key((*cmd)->str);
			if (ft_getenv(g_info.envp, key_tmp))
				ft_update_env(g_info.envp, (*cmd)->str, key_tmp);
			else
				ft_ajouter_node(&(g_info.envp), ft_new_node_env((*cmd)->str));
			free(key_tmp);
		}
		if ((*cmd)->next)
			(*cmd) = (*cmd)->next;
		else
			return ;
	}
}
