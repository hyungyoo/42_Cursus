/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 21:51:47 by keulee            #+#    #+#             */
/*   Updated: 2020/01/03 00:19:07 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//
// Description
// Deletes and frees the given element and every successor of that element,
// using the function ’del’ and free(3).
// Finally, the pointer to the list must be set to NULL.
//
// Parameters
// #1. The adress of a pointer to an element.
// #2. The adress of the function used to delete the content of the element.
//
// Return
// None
//
// External Functs.
// free
//
#include "libft.h">

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp_lst;

	if (*lst == NULL || del == NULL)
		return ;
	else
	{
		tmp_lst = *lst;
		while (*lst != NULL)
		{
			tmp_lst = tmp_lst->next;
			(*del)((*lst)->content);
			free(*lst);
			*lst = tmp_lst;
		}
		*lst = NULL;
	}
}
