/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 04:04:56 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/06/25 04:12:11 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// 연결 리스트 전체를 지우는 함수
// ft_lstdelone함수를 이용하면되지만,
// 지운다음 다음 리스트로 넘어갈수가없기때문에,
// next라는 변수를 이용한다.
// 마지막에는 NULL값을 넣어준다.
//
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next;

	if (!lst)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		ft_lstdelone(current, (del));
		current = next;
	}
	*lst = NULL;
}
