/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:07:27 by keulee            #+#    #+#             */
/*   Updated: 2019/12/18 11:52:23 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
**
** The atoi() function converts the initial portion of the string pointed to
** by str to int representation.
** It is equivalent to:(int)strtol(str, (char **)NULL, 10);
** Diffrent from ft_atoi during la piscine.(you need to control the overflow
** and underflow of int.)
*/
#include "libft.h"

int	ft_atoi(const char *str)
{
	int					mark;
	int					i;
	unsigned long int	final_nbr;

	i = 0;
	mark = 1;
	final_nbr = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			mark = mark * -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		final_nbr = final_nbr * 10 + str[i] - '0';
		i++;
		if (final_nbr > 2147483647 && mark == 1)
			return (-1);
		if (final_nbr > 2147483648 && mark == -1)
			return (0);
	}
	return (final_nbr * mark);
}
