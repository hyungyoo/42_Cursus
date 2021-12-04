/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:13:11 by seyun             #+#    #+#             */
/*   Updated: 2021/10/20 23:58:53 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (!s || ft_strlen(s) <= start || !len)
		return (ft_strdup(""));
	res = malloc(++len);
	if (!res)
		return (0);
	ft_strlcpy(res, s + start, len);
	return (res);
}
