/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:27:52 by keulee            #+#    #+#             */
/*   Updated: 2019/12/19 09:52:10 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** Description
** Allocates (with malloc(3)) and returns a substring from the string ’s’.
** The substring begins at index ’start’ and is of maximum size ’len’.
**
** Parameters
** #1. The string from which to create the substring.
** #2. The start index of the substring in the string ’s’.
** #3. The maximum length of the substring.
**
** Return
** The substring. NULL if the allocation fails.
**
** External functs.
** malloc
*/
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*copy;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	copy = (char *)ft_malloc(len + 1, sizeof(char));
	if (!(copy))
		return (NULL);
	while (s[i] != '\0' && 0 < len)
	{
		copy[j++] = s[start++];
		len--;
		i++;
	}
	copy[j] = '\0';
	return (copy);
}
