/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytak <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:08:54 by ytak              #+#    #+#             */
/*   Updated: 2022/01/25 15:36:22 by ytak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_freeall(char **s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static	size_t	ft_wordcount(const char *s, char d)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != d)
		{
			count++;
			while (s[i] && s[i] != d)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_firstword(const char *s, char d)
{
	size_t	len;
	char	*ptr;

	len = 0;
	while (s[len] && s[len] != d)
		len++;
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, len + 1);
	return (ptr);
}

static char	**ft_inside_split(const char *s, char d, size_t nbr_of_words)
{
	char	**ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	ptr = (char **)ft_calloc (nbr_of_words + 1, sizeof (char *));
	if (!ptr)
		return (NULL);
	while (i < nbr_of_words && s[j])
	{
		if (s[j] != d)
		{
			ptr[i] = ft_firstword(&s[j], d);
			if (!ptr[i++])
				return (ft_freeall(ptr));
			while (s[j] && s[j] != d)
				j++;
		}
		else
			j++;
	}
	return (ptr);
}

char	**ft_split(const char *s, char d)
{
	size_t	nbr_of_words;

	if (!s)
		return (NULL);
	nbr_of_words = ft_wordcount(s, d);
	return (ft_inside_split(s, d, nbr_of_words));
}
