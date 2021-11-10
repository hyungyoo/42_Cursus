/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:35:32 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/10 21:28:41 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_error_message_export(char *str);

int	ft_is_lettre(char c)
{
	if (c >= 34 && c <= 126)
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

void	ft_putstr_with_douq(char *str)
{
	int	i;
	int	flag_douq;

	flag_douq = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			flag_douq = 1;
			ft_putchar(str[i]);
			ft_putchar(34);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	if (flag_douq)
		ft_putchar(34);
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
		if (!(!ft_strncmp(env_sort[i], "PWD", 3) && g_info.flag_pwd == 1))
		{
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_with_douq(env_sort[i]);
			ft_putstr_fd("\n", 1);
		}
		i++;
	}
	free_tab2(env_sort);
}

void	ft_error_message_export(char *str)
{
	ft_putstr_fd("minishell: export: ", 2);
	ft_putstr_fd("'", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	g_info.exit_code = 1;
}

int	ft_check_num(char *str)
{
	int	i;
	int	flag_lettre;

	flag_lettre = 0;
	i = 0;
	while (str[i] && (str[i] != '='))
	{
		if (ft_is_lettre(str[i]))
			flag_lettre = 1;
		else if (ft_is_digit(str[i]) && flag_lettre == 0)
		{
			ft_error_message_export(str);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_str(char *str)
{
	int	i;

	if (str[0] == '=')
	{
		ft_error_message_export(str);
		return (0);
	}
	else
	{
		i = 0;
		while (str[i])
		{
			if (!(ft_is_digit(str[i]) || ft_is_lettre(str[i]) || str[i] == '='))
				return (0);
			i++;
		}
	}
	return (1);
}

int	ft_check_all(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_check_num(str[i]) || !ft_check_str(str[i]))
		{
			ft_error_message_export(str[i]);
			free_tab2(str);
			g_info.exit_code = 1;
			return (0);
		}
		i++;
	}
	return (1);
}

char	*ft_all_arg(t_node **cmd)
{
	char	*ret;

	ret = NULL;
	while (*cmd && (*cmd)->type != PIPE)
	{
		ret = ft_strjoin_free(ret, (*cmd)->str);
		if ((*cmd)->flag_nospace == 0)
			ret = ft_strjoin_free(ret, " ");
		if ((*cmd)->next)
			(*cmd) = (*cmd)->next;
		else
			break ;
	}
	return (ret);
}

void	ft_export_set_node(char **str)
{
	char	*key_tmp;
	int		i;

	i = 0;
	while (str[i])
	{
		key_tmp = ft_key(str[i]);
		if (ft_getenv(g_info.envp, key_tmp))
			ft_update_env(g_info.envp, str[i], key_tmp);
		else
			ft_ajouter_node(&(g_info.envp), ft_new_node_env(str[i]));
		free(key_tmp);
		i++;
	}
	g_info.exit_code = 0;
}

int	ft_check_arg(t_node *node)
{
	while (node && node->type != PIPE)
	{
		if (node->type == ARG || node->type == SINQ || node->type == DOUQ)
			return (1);
		if (node->next)
			node = node->next;
		else
			break ;
	}
	return (0);
}

void	ft_export(t_node **cmd)
{
	char	*all_str;
	char	**str;

	if (!cmd || !*cmd)
		return ;
	else if (!ft_check_arg(*cmd))
	{
		ft_export_env();
		return ;
	}
	(*cmd) = (*cmd)->next;
	all_str = ft_all_arg(cmd);
	str = ft_split(all_str, ' ');
	free(all_str);
	if (!ft_check_all(str))
		return ;
	ft_export_set_node(str);
	free_tab2(str);
	g_info.exit_code = 0;
}
