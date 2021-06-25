/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 04:15:00 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/06/25 04:21:54 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// 연결리스트에 f함수를 적용하여 새로운 리스틀 생성한후에
// 첫 노드의 포인터를 반환
//
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;

	if ((!(lst)) || (!(f)))
		return (NULL);
	new = f(lst);
	if (new == NULL)
		return (NULL);
	first = new;
	while (lst->next)
	{
		lst = lst->next;
		new->next = f(lst);
		if (!(new->next))
			return (NULL);
		new = new->next;
	}
	return (first);
}
