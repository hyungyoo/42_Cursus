/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 03:10:35 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/06/25 03:13:56 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// 문자열 s와 길이가 같은 문자열을 동적할당후에,
// s의 각 char에 함수f를 적용한값을 넣어 반환
// 문자열을 반환하기때문에, 널값을 넣어주어야 한다.
//
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*newstr;

	i = 0;
	if (s == NULL || (*f) == NULL)
		return (NULL);
	newstr = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!(newstr))
		return (NULL);
	while (s[i] != '\0')
	{
		newstr[i] = (*f)(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
