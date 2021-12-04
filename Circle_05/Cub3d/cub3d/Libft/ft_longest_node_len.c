/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longest_node_len.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:25:01 by seyun             #+#    #+#             */
/*   Updated: 2021/12/02 17:00:07 by seyun            ###   ########.fr       */
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
