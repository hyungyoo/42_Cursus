/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 01:26:07 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/06/25 02:39:23 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// 문자열을 정수로 변환해주는 함수이다.
//
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
