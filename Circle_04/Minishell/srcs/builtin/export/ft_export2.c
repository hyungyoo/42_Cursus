/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:35:32 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/19 18:37:16 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

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
