/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 21:49:21 by keulee            #+#    #+#             */
/*   Updated: 2019/12/26 17:44:31 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//
// Description
// Returns the last element of the list.
// 
// Parameters
// #1. The beginning of the list.
//
// Return
// Last element of the list.
//
#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
