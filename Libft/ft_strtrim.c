/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 03:02:39 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/06/25 03:07:49 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// s1 문자열의 앞과 뒤에서 set문자열을 제거한후
// 동적 할당한 문자열에 복사하여 반환
//
#include "libft.h"

unsigned int	ft_check_set(char const *s1, char c)
{
	int		i;
	char	*set;

	i = 0;
	set = (char *)s1;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	j = ft_strlen(s1) - 1;
	if (*s1 == 0)
		return (ft_strdup((char *)s1));
	if (*set == 0)
		return (ft_strdup(s1));
	while (s1[i] != '\0' && ft_check_set(set, s1[i]) == 1)
		i++;
	while (ft_check_set(set, s1[j]) == 1 && j > i)
		j--;
	return (ft_substr(s1, i, j - i + 1));
}
