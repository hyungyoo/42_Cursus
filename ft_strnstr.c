/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 21:45:58 by keulee            #+#    #+#             */
/*   Updated: 2019/12/11 22:58:26 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//
// Description
// The strnstr() function locates the first occurrence of the
// null-terminated string needle in the string haystack, 
// where not more than len characters are searched.
// Characters that appear after a `\0' character are not searched.
// Since the strnstr() function is a FreeBSD specific API,
// it should only be used when portability is not a concern.
//
// Return 
// If needle is an empty string, haystack is returned;
// if needle occurs nowhere in haystack, NULL is returned;
// otherwise a pointer to the first character of the first occurrence of needle
// is returned.
//
#include "libft.h"
#include <stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*haystack2;
	char			*needle2;

	i = 0;
	j = 0;
	haystack2 = (char *)haystack;
	needle2 = (char *)needle;
	if (needle2[i] == '\0')
		return (haystack2);
	while (haystack2[i] != '\0' && i < len)
	{
		while (haystack2[i + j] == needle2[j] && (i + j) < len)
		{
			if (needle2[j + 1] == '\0')
				return (&haystack2[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
