/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 04:22:12 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/07/29 07:36:17 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int					sign;
	long long			num;

	sign = 1;
	num = 0;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			exit(1);
		num *= 10;
		num += (*(str++) - '0');
	}
	if (num * sign > 2147483647)
		exit(1);
	if (num * sign < -2147483648)
		exit(1);
	return (num * sign);
}

static int	get_len(long long n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long long	num;
	char		*str;
	int			len;

	num = n;
	len = get_len(num);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	str[len--] = 0;
	while (num > 0)
	{
		str[len--] = '0' + num % 10;
		num /= 10;
	}
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
