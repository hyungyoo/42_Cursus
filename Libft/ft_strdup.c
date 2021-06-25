/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 02:48:13 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/06/25 02:49:50 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// "strlen(src) + 1"만큼의 메모리를 할당하여, 그안에
// src를 복사 한후, 포인터를 반환
//
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*copy;
	int		i;
	int		len;

	i = 0;
	copy = NULL;
	len = ft_strlen(src);
	copy = (char *)ft_calloc(len + 1, sizeof(char));
	if (!copy)
		return (NULL);
	while (i < len)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
