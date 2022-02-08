/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:12:41 by hyungyoo          #+#    #+#             */
/*   Updated: 2022/01/13 21:12:42 by hyungyoo         ###   ########.fr       */
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
