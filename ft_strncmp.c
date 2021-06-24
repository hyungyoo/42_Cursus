/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 13:58:58 by keulee            #+#    #+#             */
/*   Updated: 2019/12/17 18:08:15 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//
// Description
// The strncmp() function compares not more than n characters.
// Because strncmp() is designed for comparing strings rather than binary data,
// characters that appear after a `\0' character are not compared.
//
// Return
// The strcmp() and strncmp() functions return an integer
// greater than, equal to, or less than 0, according as the string s1 is
// greater than, equal to, or less than the string s2.
// The comparison is done
// using unsigned characters, so that `\200' is greater than `\0'.
//
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((str1[i] != '\0' || str2[i] != '\0') && i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
