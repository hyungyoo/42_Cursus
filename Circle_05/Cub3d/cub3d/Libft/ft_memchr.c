/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:49:27 by seyun             #+#    #+#             */
/*   Updated: 2021/10/20 23:57:32 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t size)
{
	while (size--)
	{
		if (*(unsigned char *)ptr == (unsigned char)value)
			return ((void *)ptr);
		ptr++;
	}
	return (0);
}
