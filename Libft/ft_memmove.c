/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 01:42:38 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/06/25 04:23:05 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 
// dest에 src를 size만큼 복사한다.
// 하지만, 메모리가 겹칠경우를 고려하는 함수
// 메모리 영역이 overlap된다면, src를 임시영역으로 복제한뒤에
// 임시로 복제한 영역의 데이터를 dest에 복제한다.
// 
// 예제
// int src[20];
// int dest[20];
// memcpy(dest, src, sizeof(int) * 20);
// --> dest == src
//
// 예제 overlap
// int test[20];
// memcpy(test + 4, test + 2, sizeof(int) * 20); 
// 위처럼 메모리가 겹칠경우에는 memmove함수를 쓴다.
//
// src의 주소가 dest 보다 큰값이면 문제없다.
// 반대로 src의 주소가 dest보다 작은값이면
// src의 마지막 데이터부터 한바이트씩 dest의 마지막 바이트부터
// 순서대로 복사한다.
//
#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t size)
{
	unsigned char	*dst;
	unsigned char	*src;
	unsigned int	i;

	dst = (unsigned char *)s1;
	src = (unsigned char *)s2;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
	{
		while (i < size)
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
	{
		while (0 < size--)
			dst[size] = src[size];
	}
	return (dst);
}
