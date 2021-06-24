/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 01:25:50 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/06/24 01:29:12 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// dest 포인터가 가리키는 메모리를 c라는 값으로 size만큼 set하는 함수
// 바이트 단위로 초기화하므로 c를 unsigned char형으로 casting
//
#include "libft.h"

void	*ft_memset(void *dest, int a, size_t len)
{
	unsigned int		i;
	unsigned char		c;
	char				*ptr;

	ptr = (char *)dest;
	i = 0;
	c = a;
	while (i != len)
	{
		ptr[i] = a;
		i++;
	}
	return (ptr);
}
