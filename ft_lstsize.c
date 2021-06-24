/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 21:48:57 by keulee            #+#    #+#             */
/*   Updated: 2019/12/26 17:29:04 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//
// Description
// Counts the number of elements in a list.
//
// Parameters
// #1. The beginning of the list.
//
// Return
// Length of the list.
//
// External functs.
// None
//
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
//
// Test1
// t_list *l;
// int actual;
// int expected;
//
// l = lstnew(strdup("1"));
// l->next = lstnew(strdup("2"));
// l->next->next = lstnew(strdup("3"));
// expected = 3;
// actual = ft_lstsize(l);
// if (actual == expected)
//  exit(TEST_SUCCESS);
// exit(TEST_FAILED);
//
// Test2
// t_list *l = ((void *)0);
// int actual;
// int expected = 0;
// actual = ft_lstsize(l);
// if (actual == expected)
//		exit(TEST_SUCCESS);
//	exit(TEST_FAILED);
