/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 01:02:01 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/06/25 01:14:36 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// dest문자열에 src문자열을 "size - strlen(dest) - 1"만큼 이어 붙이고
// 마지막에 널 문자를 넣어준다.
// 반환되는 값은 문자열의 총 길이이다.
//
// 리턴값 :
// size < strlen(dest)의 경우 : size + strlen(str), "dest는 그대로"
// size >= strlen(dest)의 경우 : strlen(src) + strlen(dest)
//
#include "libft.h"

size_t	ft_strlcat(char *restrict dest, const char *restrict src,
size_t size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (size < dest_len)
		return (src_len + size);
	while (src[i] != '\0' && (dest_len + i) < size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
