/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 03:22:59 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/06/25 03:32:26 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// 새로운 연결리스트를 생성하는 함수
// content의 멤버에 인자로 들어온 content를 넣어준다.
// next는 NULL로 
// 반환값은 새로운 리스트의 주소
//
#include "libft.h"

t_list	*ft_lstnew(void	*content)
{
	t_list	*res;

	res = (t_list *)malloc(sizeof(t_list));
	if (!(res))
		return (NULL);
	res->content = content;
	res->next = NULL;
	return (res);
}
