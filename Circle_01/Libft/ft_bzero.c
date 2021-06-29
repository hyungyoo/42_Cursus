/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 01:29:33 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/06/24 01:30:47 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 
// dest 포인터가 가리키는 메모리를 널 값으로 size만큼 초기화 시킨다.
//
#include "libft.h"

void	ft_bzero(void *dest, size_t n)
{
	unsigned char	*ptr;
	unsigned int	i;

	i = 0;
	ptr = (unsigned char *)dest;
	if (n == 0)
		return ;
	while (i != n)
	{
		ptr[i] = 0;
		i++;
	}
}
