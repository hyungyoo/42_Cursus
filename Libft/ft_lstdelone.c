/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 04:01:43 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/06/25 04:04:35 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 
// 인자로 들어온 리스트를 지우는 함수
// 리스트의 content를 지우는 del함수의 포인터가 인자로 들어온다.
// del 함수에 lst->content를 넘겨준후 lst를 free한다
//
#include "libft.h"

void	ft_lstdelone(t_list *lst, void(*del)(void *))
{
	if (!lst)
		return ;
	if (del)
		del(lst->content);
	free(lst);
}
