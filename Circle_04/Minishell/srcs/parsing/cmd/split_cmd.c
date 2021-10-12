/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 22:14:47 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/12 19:37:52 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_strcmp_pivot(char *str)
{
	if (!ft_strcmp(str, "|"))
		return (5);
	else if (!ft_strcmp(str, "<"))
		return (6);
	else if (!ft_strcmp(str, "<<"))
		return (7);
	else if (!ft_strcmp(str, ">"))
		return (8);
	else if (!ft_strcmp(str, ">>"))
		return (9);
	return (0);
}

int	ft_count_pivot(char **str)
{
	int	count_pivot;
	int	i;

	i = 0;
	count_pivot = 0;
	while (str[i])
	{
		if (ft_strcmp_pivot(str[i]))
			count_pivot++;
		i++;
	}
	return (count_pivot);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*ret;
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	tmp = ft_strjoin(s1, " ");
	ret = ft_strjoin(tmp, s2);
	free(tmp);
	free(s1);
	return (ret);
}

char	**ft_split_cmd(char **str)
{
	char	**ret;
	int		i;
	int		ret_index;

	ret = ft_calloc(sizeof(char *), ft_count_pivot(str) + 2);
	i = 0;
	ret_index = 0;
	while (str[i])
	{
		if (i == 0 && ft_strcmp_pivot(str[i]))
			ret[ret_index++] = ft_strdup(str[i++]);
		else if (str[i])
		{
			ret[ret_index] = ft_strdup(str[i++]);
			while (str[i] && !ft_strcmp_pivot(str[i]))
				ret[ret_index] = ft_strjoin_free(ret[ret_index], str[i++]);
			if (str[i] && ft_strcmp_pivot(str[i]))
				ret[ret_index] = ft_strjoin_free(ret[ret_index], str[i++]);
			ret_index++;
		}
	}
	ft_free_double(str);
	return (ret);
}
