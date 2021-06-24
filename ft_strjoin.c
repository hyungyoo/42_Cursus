/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:48:57 by keulee            #+#    #+#             */
/*   Updated: 2019/12/17 19:11:36 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//
// Description
// Allocates (with malloc(3)) and returns a new string,
// which is the result of the concatenation of ’s1’ and ’s2’.
//
// Parameter
// #1. The prefix string.
// #2. The suffix string.
//
// Return
// The new string. NULL if the allocation fails.
//
// External functs.
// Malloc
//
#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	new_str_len;
	unsigned int	i;
	unsigned int	j;
	char			*new;

	i = 0;
	j = 0;
	new_str_len = ft_strlen(s1) + ft_strlen(s2);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new = (char *)ft_calloc((new_str_len + 1), sizeof(char));
	if (!(new))
		return (NULL);
	while (s1[i] != '\0')
		new[i++] = (char)s1[j++];
	j = 0;
	while (s2[j] != '\0')
		new[i++] = (char)s2[j++];
	new[i] = '\0';
	return (new);
}
