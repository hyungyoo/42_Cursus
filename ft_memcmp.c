/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:06:06 by keulee            #+#    #+#             */
/*   Updated: 2019/12/17 15:40:01 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//
//
//The memcmp() function compares byte string s1 against byte string s2.
// Both strings are assumed to be n bytes long.
//
// Return
// The memcmp() function returns zero if the two strings are identical, 
// otherwise returns the difference between the first two differing bytes
// (treated as unsigned char values,
// so that `\200' is greater than `\0', for example).
// Zero-length strings are always identical.
// This behavior is not required by C and portable code should
// only depend on the sign of the returned value.
//
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	unsigned int	i;

	i = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	if (s1 == s2 || n == 0)
		return (0);
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}
