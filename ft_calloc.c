/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:08:07 by keulee            #+#    #+#             */
/*   Updated: 2019/12/18 14:24:26 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** The calloc() function contiguously allocates enough space for count objects
** that are size bytes of 
** memory each and returns a pointer to the allocated memory. 
** The allocated memory is filled with bytes of value zero (0).
*/
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
