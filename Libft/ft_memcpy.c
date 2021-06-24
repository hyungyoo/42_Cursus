/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 01:31:10 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/06/24 01:41:34 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// 메모리 영역을 복사
// src를 dest에 size만큼 바이트(char*) 단위로 복사
//
#include "libft.h"

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	char			*s1;
	char			*s2;
	unsigned int	i;

	s1 = (char *)dest;
	s2 = (char *)src;
	i = 0;
	if (n == 0 || src == dest)
		return (s1);
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}
