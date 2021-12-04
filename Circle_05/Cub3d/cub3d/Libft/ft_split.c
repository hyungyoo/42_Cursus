/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 23:19:58 by seyun             #+#    #+#             */
/*   Updated: 2021/10/20 23:56:04 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_row(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			++cnt;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	*from;
	size_t	idx;
	size_t	size;

	res = (char **)malloc(sizeof(char *) * get_row(s, c) + 1);
	if (!res)
		return (0);
	idx = 0;
	while (*s)
	{
		if (*s != c)
		{
			from = (char *)s;
			while (*s && *s != c)
				++s;
			size = s - from + 1;
			if (!(res[idx] = (char *)malloc(size)))
				return (0);
			ft_strlcpy(res[idx++], from, size);
		}
		else
			++s;
	}
	res[idx] = 0;
	return (res);
}
