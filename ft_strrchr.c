/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:24:56 by keulee            #+#    #+#             */
/*   Updated: 2019/12/17 17:27:43 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//
// Description
// The strrchr() function is identical to strchr(),
// except it locates the last occurrence of c.
// The terminating null character is considered to be part of the string;
// therefore if c is `\0', the functions locate the terminating `\0'.
//
// Return
// The functions strchr() and strrchr()
// return a pointer to the located character,
// or NULL if the character does not appear in the string.
//
#include "libft.h"
#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	needle;
	int		i;

	needle = c;
	ptr = (char *)s;
	i = ft_strlen(s);
	if (ptr[i] == needle)
		return (&ptr[i]);
	while (i != 0)
	{
		if ((ptr[i - 1]) == needle)
			return (&ptr[i - 1]);
		i--;
	}
	return (NULL);
}
