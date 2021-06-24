/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:45:49 by keulee            #+#    #+#             */
/*   Updated: 2019/12/11 21:31:19 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//
// Description
// The strchr() function locates the first occurrence of c
// (converted to a char) in the string pointed to by s.
// The terminating null character is considered to be part of the string;
// therefore if c is `\0', the functions locate the terminating `\0'.
// The strrchr() function is identical to strchr(),
// except it locates the last occurrence of c.
//
// Return
// The functions strchr() and strrchr()
// return a pointer to the located character, 
// or NULL if the character does not appear in the string.
//
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	needle;
	int		i;

	needle = c;
	ptr = (char *)s;
	i = 0;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == c)
			return (ptr + i);
		i++;
	}
	if (ptr[i] == c)
		return (ptr + i);
	return (NULL);
}
