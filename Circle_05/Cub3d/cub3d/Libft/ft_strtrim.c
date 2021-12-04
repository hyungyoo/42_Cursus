/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:10:21 by seyun             #+#    #+#             */
/*   Updated: 2021/10/21 00:01:03 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isincluded(char a, char const *set)
{
	while (*set)
		if (a == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	char	*begin;
	char	*until;
	size_t	len;

	begin = (char *)s1;
	until = begin + ft_strlen(s1);
	while (*begin && isincluded(*begin, set))
		++begin;
	while (begin < until && isincluded(*(until - 1), set))
		--until;
	len = until - begin + 1;
	res = malloc(len);
	if (!res)
		return (0);
	ft_strlcpy(res, begin, len);
	return (res);
}
