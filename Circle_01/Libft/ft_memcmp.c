/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 03:17:33 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/06/25 03:18:42 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// n만큼 (unsigned char*)로 캐스팅한 s1, s2를 비교하여
// 다르다면, s1[i] - s2[i]의 값을 반환
// 아니라면 널값을 반환
//
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	unsigned int	i;

	i = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	if (s1 == s2 || n == 0)
		return (0);
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}
