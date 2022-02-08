/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:16:18 by hyungyoo          #+#    #+#             */
/*   Updated: 2022/01/13 21:16:21 by hyungyoo         ###   ########.fr       */
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
