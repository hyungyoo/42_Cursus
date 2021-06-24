/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 02:24:07 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/06/24 02:25:30 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// s를 size만큼 바이트 단위로 검사하여 c를 발견한다면
// c가 존재하는 인덱스 주소를 반환한다.
// 바이트단위로 검사하므로, s는 (char*)형으로 c는 unsigned char형으로 casting
//
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	needle;
	unsigned char	*ptr;
	unsigned int	i;

	needle = c;
	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if (ptr[i] == needle)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}
