/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 21:46:52 by keulee            #+#    #+#             */
/*   Updated: 2019/12/21 18:14:44 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//
// Description
// Adds the element ’new’ at the beginning of the list.
//
// Parameters
// #1. The address of a pointer to the first link of a list.
// #2. The address of a pointer to the element to be added to the list.
//
// Return
// None
//
#include "libft.h"
#include <stdlib.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
