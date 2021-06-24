/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 21:50:51 by keulee            #+#    #+#             */
/*   Updated: 2020/01/04 00:09:16 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//
// Description
// Takes as a parameter an element and frees the memory of the element’s content
// using the function ’del’ given as a parameter and free the element.
// The memory of ’next’ must not be freed.
//
// Parameters
// #1. The element to free.
// #2. The address of the function used to delete the content.
//
// Return
// None
//
// External functs.
// free
//
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst != NULL && (*del) != NULL)
	{
		(*del)(lst->content);
		free(lst);
	}
}
