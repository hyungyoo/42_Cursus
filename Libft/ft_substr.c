/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 02:53:28 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/06/25 02:58:28 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// s문자열에서 start 인덱스부터 시작하는 len길이만큼 문자열을 "len + 1"길이만큼의
// 새로운 메모리를 할당하여 복사해 반환
// 인덱스의 위치가 strlen(s)보다 크거나, s가 널값일떄는 널문자 하나만 있는
// 문자열을 반환
//
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*copy;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	copy = (char *)ft_malloc(len + 1, sizeof(char));
	if (!(copy))
		return (NULL);
	while (s[i] != '\0' && 0 < len)
	{
		copy[j++] = s[start++];
		len--;
		i++;
	}
	copy[j] = '\0';
	return (copy);
}
