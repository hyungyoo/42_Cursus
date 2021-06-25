/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 02:46:38 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/06/25 02:47:53 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// size * count 크기의 메모리를 할당하고
// bzero함수로 널값으로 초기화 하여 반환
//
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*copy;

	copy = (void *)malloc(size * count);
	if (!(copy))
		return (NULL);
	ft_bzero(copy, size * count);
	return (copy);
}
