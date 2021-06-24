/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 19:13:30 by keulee            #+#    #+#             */
/*   Updated: 2019/12/16 17:31:33 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//
// Description
// Applies the function ’f’ to each character of the string ’s’
// to create a new string (with malloc(3))resulting
// from successive applications of ’f’.
//
// Parameters
// #1. The string on which to iterate.
// #2. The function to apply to each character.
//
// Return
// The string created from the successive applications of ’f’.
// Returns NULL if the allocation fails.
//
// Externel functs.
// Malloc
//
#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*newstr;

	i = 0;
	if (s == NULL || (*f) == NULL)
		return (NULL);
	newstr = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!(newstr))
		return (NULL);
	while (s[i] != '\0')
	{
		newstr[i] = (*f)(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
