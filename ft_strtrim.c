/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 15:35:15 by keulee            #+#    #+#             */
/*   Updated: 2019/12/19 10:22:19 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//
// Description
// Allocates (with malloc(3)) and returns a copy of ’s1’
// with the characters specified in ’set’ 
// removed from the beginning and the end of the string.
//
// Parameters
// #1. The string to be trimmed.
// #2. The reference set of characters to trim.
//
// Return
// The trimmed string. NULL if the allocation fails.
//
// External functs.
// Malloc
//
#include "libft.h"
#include <stdlib.h>

unsigned int	ft_check_set(char const *s1, char c)
{
	int		i;
	char	*set;

	i = 0;
	set = (char *)s1;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	j = ft_strlen(s1) - 1;
	if (*s1 == 0)
		return (ft_strdup((char *)s1));
	if (*set == 0)
		return (ft_strdup(s1));
	while (s1[i] != '\0' && ft_check_set(set, s1[i]) == 1)
		i++;
	while (ft_check_set(set, s1[j]) == 1 && j > i)
		j--;
	return (ft_substr(s1, i, j - i + 1));
}
//
// Test
//
//int		main(void)
//{
//	char *s1 = "\t \n\n \t\t \n\n\nHello \t  Please\n Trim me !\n  \n \n \t\t\n";
//
//	printf("%s\n", ft_strtrim(s1, " \n\t"));
//	return (0);
//}
