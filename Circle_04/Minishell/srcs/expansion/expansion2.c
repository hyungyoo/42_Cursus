/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:59:28 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/23 02:36:54 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	malloc_new_str(char **new_str, char c)
{
	int	i;

	i = 0;
	(*new_str) = (char *)malloc(sizeof(char) * 2);
	if (!*new_str)
		return ;
	(*new_str)[i++] = c;
	(*new_str)[i] = '\0';
}

void	ft_ajouter_char(char **new_str, char c)
{
	int		size;
	char	*tmp;
	char	*ret;
	int		i;

	i = 0;
	if (!*new_str)
	{
		malloc_new_str(new_str, c);
		return ;
	}
	size = ft_strlen(*new_str) + 1;
	ret = (char *)malloc(sizeof(char) * size + 1);
	if (!ret)
		return ;
	while ((*new_str)[i])
	{
		ret[i] = (*new_str)[i];
		i++;
	}
	ret[i++] = c;
	ret[i] = '\0';
	tmp = *new_str;
	*new_str = ret;
	free(tmp);
}

char	*tmp_key_expansion(char *str, int *i, int j)
{
	int		size;
	int		k;
	char	*tmp_key;

	size = *i - j;
	tmp_key = NULL;
	tmp_key = (char *)malloc(sizeof(char) * size + 1);
	if (!tmp_key)
		return (NULL);
	k = 0;
	while (k < size)
		tmp_key[k++] = str[j++];
	tmp_key[k] = '\0';
	return (tmp_key);
}

int	check_exit_char(char c)
{
	if (c == ' ' || c == '|' || c == 39 || c == '$' || c == '=' || c == '!')
		return (1);
	return (0);
}

void	ft_ajouter_dolr(char **new_str, char *str, int *i)
{
	int		j;
	char	*tmp_key;

	(*i)++;
	j = *i;
	while (str[*i])
	{
		if (check_exit_char(str[*i]))
			break ;
		(*i)++;
	}
	tmp_key = tmp_key_expansion(str, i, j);
	if (ft_getenv(g_info.envp, tmp_key))
		*new_str = ft_strjoin_free(*new_str, ft_getenv(g_info.envp, tmp_key));
	else
		*new_str = ft_strjoin_free(*new_str, "");
	free(tmp_key);
}

void	ft_ajouter_exit_code(char **new_str, int *i)
{
	char	*num;

	num = NULL;
	num = ft_itoa(g_info.exit_code);
	*new_str = ft_strjoin_free(*new_str, num);
	free(num);
	(*i) = (*i) + 2;
}
