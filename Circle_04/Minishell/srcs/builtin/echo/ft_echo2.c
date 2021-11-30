/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 02:26:25 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/30 16:47:54 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_echo_type_douq_sans_espace(char **key, char *str)
{
	int	i;

	i = 0;
	while (key[i])
	{
		if (i == 0 && str[0] != '$')
			ft_putstr(key[i]);
		else if (!ft_strcmp(key[i], "?"))
			ft_putnbr_fd(g_info.exit_code, 1);
		else
		{
			if (ft_getenv_echo(g_info.envp, key[i]))
				ft_putstr(ft_getenv_echo(g_info.envp, key[i]));
		}
		i++;
	}
}

int	ft_check_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 39)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_find_key(char *str, int start_index, int *last_index)
{
	char	*ret;
	int		size_str;
	int		i;

	i = 0;
	size_str = *last_index - start_index + 1;
	ret = (char *)malloc(sizeof(char) * size_str + 1);
	if (!ret)
		return (NULL);
	while (i < size_str)
	{
		ret[i] = str[start_index];
		i++;
		start_index++;
	}
	ret[i] = '\0';
	return (ret);
}

int	ft_check_last(char *str, int *last_index)
{
	if (str[*last_index] == 39 || str[(*last_index)] == '$'
		|| str[*last_index] == ' ' || !str[(*last_index)])
	{
		(*last_index)--;
		return (1);
	}
	return (0);
}

void	ft_print_env_quote(char *str, int *last_index)
{
	int		start_index;
	char	*find_key;

	start_index = ++(*last_index);
	while (42)
	{
		if (ft_check_last(str, last_index))
		{
			find_key = ft_find_key(str, start_index, last_index);
			if (!ft_getenv_echo(g_info.envp, find_key))
			{
				free(find_key);
				return ;
			}
			ft_putstr(ft_getenv_echo(g_info.envp, find_key));
			free(find_key);
			return ;
		}
		(*last_index)++;
	}
}
