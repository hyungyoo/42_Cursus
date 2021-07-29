/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:36:34 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/06/23 20:21:04 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void			ft_error(char *errstr)
{
	write(1, "Error : ", 8);
	write(1, errstr, ft_strlen(errstr));
	write(1, "\n", 1);
	exit(1);
}

int				ft_atoi(char *str)
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
			ft_error("It's not integer");
		num *= 10;
		num += (*(str++) - '0');
	}
	if (num * sign > 2147483647)
		ft_error("Integer out of range");
	if (num * sign < -2147483648)
		ft_error("Integer out of range");
	return (num * sign);
}

static int		get_len(long long n)
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

char			*ft_itoa(int n)
{
	long long	num;
	char		*str;
	int			len;

	num = n;
	len = get_len(num);
	if (!(str = (char *)malloc(len + 1)))
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

size_t			ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
