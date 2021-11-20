/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:35:32 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/20 19:21:28 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_check_egal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i != 0 && str[i] == '=' && str[i - 1] == ' ')
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

void	ft_check_all(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_check_str(str[i]) || !ft_strcmp(str[i], "=")
			|| !ft_check_egal(str[i]))
		{
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
