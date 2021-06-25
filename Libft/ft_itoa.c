/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 03:09:33 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/06/25 03:10:16 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// 정수를 문자열로 변환해주는 함수
// 필요한 문자열의 길이만큼 동적할당후, 반환
//
#include "libft.h"

int	ft_int_len(int n)
{
	int	i;

	if (n < 0)
		i = 1;
	else
		i = 0;
	if (n < 0)
		n = n * -1;
	if (n == 0)
		i = 1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	ft_mark(int *n, int *mark)
{
	if (*n < 0)
		*mark = 1;
	else
		*mark = 0;
}

char	*ft_itoa(int n)
{	
	int		i;
	char	*str;
	int		mark;

	ft_mark(&n, &mark);
	i = ft_int_len(n);
	str = (char *)ft_calloc((i + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		n = n * -1;
	str[i] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[i - 1] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	if (mark == 1)
		str[0] = '-';
	return (str);
}
