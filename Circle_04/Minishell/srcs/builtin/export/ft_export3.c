/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:35:32 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/18 12:03:34 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

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
