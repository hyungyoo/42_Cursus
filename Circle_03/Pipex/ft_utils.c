/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:17:11 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/07/27 14:17:12 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
 * print error + exit()
 */
void	ft_print_error(char *str)
{
	while (*str)
		write(2, str++, 1);
	exit(0);
}

int	ft_strncmp(char *s1, char *s2, int	size)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && i < size)
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_size;
	int		s2_size;
	char	*ret;
	int		i;

	i = 0;
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (s1_size + s2_size) + 1);
	if (!ret)
		return (NULL);
	while (*s1)
	{
		ret[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		ret[i++] = *s2;
		s2++;
	}
	ret[i] = '\0';
	return (ret);
}
