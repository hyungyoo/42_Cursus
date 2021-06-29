/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 02:27:47 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/06/24 02:29:30 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// dest문자열에 src문자열을 "size - 1"만큼 복사하고 마지막에 널 문자를 넣어준다.
// 널 문자를 보장해준다는 점에서 strcpy보다 안정적이다.
// 반환값은 src의 문자열 길이
//
#include "libft.h"

size_t	ft_strlcpy(char *restrict dest, const char *restrict src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (dest == 0)
		return (0);
	while (src[j] != '\0')
		j++;
	if (size == 0)
		return (j);
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (j);
}
