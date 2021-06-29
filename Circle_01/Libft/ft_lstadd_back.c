/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 03:57:50 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/06/25 04:01:19 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// 연결리스트 마지막에 new를 추가하는 함수
// 메모리 주소가 가리키는 연결리스트가 비어있다면
// 새로운 리스트가 첫 요소이자 마지막요소가 됨
//
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_list;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_list = ft_lstlast(*lst);
	last_list->next = new;
}
