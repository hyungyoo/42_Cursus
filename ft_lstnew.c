/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 21:45:32 by keulee            #+#    #+#             */
/*   Updated: 2019/12/21 16:37:55 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//
// Description
// Allocates (with malloc(3)) and returns a new element.
// The variable ’content’ is initialized with the value of the parameter
// ’content’.
// The variable ’next’ is initialized to NULL.
//
// Parameters
// #1. The content to create the new element with.
//
// Return
// The new element.
//
// External functs.
// malloc
//
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_element;

	new_element = malloc(sizeof(t_list));
	if (!(new_element))
		return (NULL);
	new_element->content = content;
	new_element->next = (NULL);
	return (new_element);
}

// For test
// int    main(void)
//{
//  t_list *lst;
//  
//  char	str[] = "test";
//  
//  lst = ft_lstnew((void *)str);
//  printf("\n%s\n", str->content);
//}
