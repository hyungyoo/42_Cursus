/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:24:23 by seyun             #+#    #+#             */
/*   Updated: 2021/10/21 00:02:17 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *ptr)
{
	size_t	len;
	size_t	i;
	char	*res;

	len = ft_strlen(ptr);
	res = malloc(len + 1);
	if (!res)
		return (0);
	i = 0;
	while (len--)
		res[i++] = *ptr++;
	res[i] = 0;
	return (res);
}
