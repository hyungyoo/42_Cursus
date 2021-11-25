/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:35:32 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/25 05:49:33 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_check_egal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] == '=')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_str(char *str)
{
	int	i;


	if (str[0] == '=' || ft_is_digit(str[0]))
		return (0);
	i = 0;
	while (str[i])
	{
		if (!ft_is_lettre(str[i]))
			return (0);
		i++;
	}
	return (1);
}

// strstr == ft_strstr 
int	ft_check_value(char *str)
{
	t_envp	*envp;
	t_envp	*tmp;
	char	*key_tmp;

	//if (str[0] != '$')	--> for haha=1244 
	//	return (0);
	envp = g_info.envp;
	tmp = envp->prev;
	key_tmp = ft_key(str);
	while (envp != tmp)
	{
		if (strstr(key_tmp, envp->envp_value) && !strstr(key_tmp, ft_getenv(g_info.envp, "USER")))
		{
			free(key_tmp);
			return (1);
		}
		envp = envp->next;
	}
	if (strstr(key_tmp, envp->envp_value) && !strstr(key_tmp, ft_getenv(g_info.envp, "USER")))
	{
		free(key_tmp);
		return (1);
	}
	free(key_tmp);
	return (0);
}

// ret == int for num of array
void	ft_check_all(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_check_str(str[i]) || !ft_strcmp(str[i], "=")
			|| !ft_check_egal(str[i]) || ft_check_value(str[i]))
		{

				/* for check */
				if (!ft_check_str(str[i]))
					printf("check str\n");
				if (!ft_strcmp(str[i], "="))
					printf("check strcmp\n");
				if (!ft_check_egal(str[i]))
					printf("check egal\n");
				if (ft_check_value(str[i]))
					printf("check value\n");
				/* for check */

				ft_error_message_export(str[i]);
				g_info.exit_code = 1;
		}
		i++;
	}
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
}
