/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 01:18:04 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/06/25 01:19:43 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// strchr과 비슷하지만, 맨 뒤에있는 (char)c를 반환한다.
// 없다면 strchr과 같이 널 포인터를 반환
//
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	needle;
	int		i;

	needle = c;
	ptr = (char *)s;
	i = ft_strlen(s);
	if (ptr[i] == needle)
		return (&ptr[i]);
	while (i != 0)
	{
		if ((ptr[i - 1]) == needle)
			return (&ptr[i - 1]);
		i--;
	}
	return (NULL);
}
