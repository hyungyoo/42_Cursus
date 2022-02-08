/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:12:49 by hyungyoo          #+#    #+#             */
/*   Updated: 2022/01/13 21:12:49 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int val, size_t size)
{
	void	*res;

	res = dest;
	while (size--)
		*(char *)dest++ = (unsigned char)val;
	return (res);
}
