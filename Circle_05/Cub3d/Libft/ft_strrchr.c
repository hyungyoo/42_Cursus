/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 21:42:59 by seyun             #+#    #+#             */
/*   Updated: 2021/10/20 23:57:50 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*res;

	res = 0;
	while (1)
	{
		if (*s == (char)c)
			res = s;
		if (*s == 0)
			break ;
		s++;
	}
	return ((char *)res);
}
