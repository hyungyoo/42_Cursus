/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 16:04:30 by keulee            #+#    #+#             */
/*   Updated: 2020/01/03 16:15:56 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//
// Description
// Iterates the list ’lst’ and applies the function ’f’
// to the content of each element.
//
// Parameters
// #1. The adress of a pointer to an element.
// #2. The adress of the function used to iterate on the list.
//
// Return
// None
//
// External functs.
// None
//
#include "libft.h"
#include <stdlib.h>

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || (*f) == NULL)
		return ;
	else
	{
		while (lst != NULL)
		{
			(*f)(lst->content);
			lst = lst->next;
		}
	}
}
