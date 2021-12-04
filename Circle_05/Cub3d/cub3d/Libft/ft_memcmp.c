/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:08:25 by seyun             #+#    #+#             */
/*   Updated: 2021/10/20 23:46:58 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *p1, const void *p2, size_t size)
{
	while (size--)
	{
		if (*(char *)p1 != *(char *)p2)
			return (*(unsigned char *)p1 - *(unsigned char *)p2);
		p1++;
		p2++;
	}
	return (0);
}
