/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 21:50:05 by keulee            #+#    #+#             */
/*   Updated: 2019/12/26 19:04:31 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
** Description
** Adds the element ’new’ at the end of the list.
**
** Parameters
** #1. The address of a pointer to the first link of a list.
** #2. The address of a pointer to the element to be added to the list.
**
** Return
** None
**
** External functs.
** None
*/
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*start;

	start = NULL;
	if (*lst == NULL)
		*lst = new;
	else
	{
		start = *lst;
		while (start->next != NULL)
			start = start->next;
		start->next = new;
	}
}

/*
** Test1
** Test code:
**	t_list *l = lstnew(strdup("nyacat"));
**	t_list *n = lstnew(strdup("OK"));
**	ft_lstadd_back(&l, n);
**	if (l->next == n && !strcmp(l->next->content, "OK"))
**	{
**		exit(TEST_SUCCESS);
**	}
**	exit(TEST_FAILED);
**
** Test2
**	t_list *l = lstnew(strdup("nyacat"));
**	t_list *n = lstnew(strdup("OK"));
**	ft_lstadd_back(&l, n);
**	if (l->next == n && !strcmp(l->next->content, "OK"))
**	{
**		free(l->next);
**		free(l);
**		exit(TEST_SUCCESS);
**	}
**	free(l->next);
**	free(l);
**	exit(TEST_FAILED);
**
** Test3
**t_list *l = ((void *)0);
**	t_list *n = lstnew(strdup("OK"));
**	ft_lstadd_back(&l, n);
**	if (l == n && !strcmp(l->content, "OK"))
**	{
**		free(l->next);
**		free(l);
**		exit(TEST_SUCCESS);
**	}
**	free(l->next);
**	free(l);
**	exit(TEST_FAILED);
*/
