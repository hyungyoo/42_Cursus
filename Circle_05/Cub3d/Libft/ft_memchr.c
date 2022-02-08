/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:12:09 by hyungyoo          #+#    #+#             */
/*   Updated: 2022/01/13 21:12:10 by hyungyoo         ###   ########.fr       */
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
