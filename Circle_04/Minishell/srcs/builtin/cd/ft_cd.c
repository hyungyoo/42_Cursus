/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:54:30 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/30 20:16:08 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_error_message_cd(char *new_path)
{
	if (new_path)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(new_path, 2);
		perror(" \b");
	}
	else
	{
		ft_putstr_fd("minishell: cd", 2);
		perror(" ");
	}
	g_info.exit_code = 1;
}

int	ft_new_path(char **path, char *new_path)
{
	free(*path);
	*path = ft_strdup(new_path);
	if (chdir(*path) == -1)
	{
		ft_error_message_cd(*path);
		return (0);
	}
	return (1);
}

int	ft_is_slash(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

char	**ft_split_cd(char *new_path)
{
	char	**ret;
	char	*tmp;

	ret = NULL;
	tmp = NULL;
	if (ft_is_slash(new_path))
		ret = ft_split(new_path, '/');
	else
	{
		tmp = ft_strjoin(new_path, "/");
		ret = ft_split(tmp, '/');
		free(tmp);
		tmp = NULL;
	}
	return (ret);
}
