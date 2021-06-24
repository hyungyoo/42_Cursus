/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 01:37:09 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/06/24 01:40:57 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// src를 dest에 c가 나올때까지(c포함), 또는 size만큼 복사한다.
// 반환값은 (s1 + i + 1), 즉 dest가 가리키는 메모리영역에서 c가 복사된 인덱스
// 다음 인덱스 주소를 반환함
//
#include "libft.h"

void	*ft_memccpy(void *restrict dest, const void *restrict src, int c,
size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned int	i;
	unsigned char	needle;

	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	needle = c;
	i = 0;
	if (s1 == s2 || n == 0)
		return (NULL);
	while (i < n)
	{
		s1[i] = s2[i];
		if (s1[i] == needle)
			return (s1 + i + 1);
		i++;
	}
	return (NULL);
}
