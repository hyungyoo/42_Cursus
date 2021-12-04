/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 13:05:27 by seyun             #+#    #+#             */
/*   Updated: 2021/10/21 00:01:32 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	void	*res;

	if (!dest && !src)
		return (0);
	res = dest;
	if (src < dest)
	{
		src += size;
		dest += size;
		while (size--)
			*(char *)--dest = *(char *)--src;
	}
	else
		while (size--)
			*(char *)dest++ = *(char *)src++;
	return (res);
}
