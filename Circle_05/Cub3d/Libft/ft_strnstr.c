/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:15:54 by hyungyoo          #+#    #+#             */
/*   Updated: 2022/01/13 21:15:55 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *litt, size_t len)
{
	size_t		len_b;
	size_t		len_l;
	size_t		size;

	if (*litt == 0)
		return ((char *)big);
	len_b = ft_strlen(big);
	len_l = ft_strlen(litt);
	if (len_b < len_l || len < len_l)
		return (0);
	if (len_b > len)
		size = len;
	else
		size = len_b;
	while (size-- >= len_l)
	{
		if (ft_memcmp(big, litt, len_l) == 0)
			return ((char *)big);
		big++;
	}
	return (0);
}
