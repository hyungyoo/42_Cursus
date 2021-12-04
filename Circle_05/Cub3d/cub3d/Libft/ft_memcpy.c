/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:12:23 by seyun             #+#    #+#             */
/*   Updated: 2021/10/20 23:52:24 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	void	*res;

	if (!dest && !src)
		return (0);
	res = dest;
	while (size--)
		*(char *)dest++ = *(char *)src++;
	return (res);
}
