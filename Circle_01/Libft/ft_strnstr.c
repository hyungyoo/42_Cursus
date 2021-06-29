/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 01:20:04 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/06/25 01:23:55 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// haystack에서 len만큼 needle문자열을 검색한다.
// str이 needle문자열을 전부다 포함한다면, str에서 find가 시작되는
// 인덱스의 주소를 반환한다.
// 포함하지않는 다면 널 포인터를 반환한다.
//
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*haystack2;
	char			*needle2;

	i = 0;
	j = 0;
	haystack2 = (char *)haystack;
	needle2 = (char *)needle;
	if (needle2[i] == '\0')
		return (haystack2);
	while (haystack2[i] != '\0' && i < len)
	{
		while (haystack2[i + j] == needle2[j] && (i + j) < len)
		{
			if (needle2[j + 1] == '\0')
				return (&haystack2[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
