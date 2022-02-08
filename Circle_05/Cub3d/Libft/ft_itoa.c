/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:10:15 by hyungyoo          #+#    #+#             */
/*   Updated: 2022/01/13 21:10:17 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_len(int n)
{
	int	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_sign(int n)
{
	int	sign;

	sign = 0;
	if (n < 0)
		sign = -1;
	else
		sign = 1;
	return (sign);
}

char	*ft_itoa(int n)
{
	int			len;
	int			sign;
	char		*res;
	long long	tmp;

	sign = ft_sign(n);
	len = ft_get_len(n);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len] = 0;
	len--;
	tmp = (long long)n;
	if (n < 0)
		tmp = -(long long)n;
	while (len >= 0)
	{
		res[len] = '0' + tmp % 10;
		tmp /= 10;
		len--;
	}
	if (sign == -1)
		res[0] = '-';
	return (res);
}
