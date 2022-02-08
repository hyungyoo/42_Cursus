/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longest_node_len.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:10:23 by hyungyoo          #+#    #+#             */
/*   Updated: 2022/01/13 21:10:24 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_longest_node_len(t_list *lst)
{
	int	max;

	max = -1;
	while (lst)
	{
		if (max < (int)ft_strlen((char *)lst->content))
			max = (int)ft_strlen((char *)lst->content);
		lst = lst->next;
	}
	return (max);
}
