/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:55:49 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/07/22 14:55:50 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int	ft_atoi_size(char *num)
{
	long long	ret;
	int			sign;
	int			i;

	ret = 0;
	i = 0;
	sign = 1;
	if (num[i] == '-' || num[i] == '+')
	{
		if (num[i] == '-')
			sign *= -1;
		i++;
	}
	while (num[i])
	{
		ret = (ret * 10) + (num[i] - '0');
		i++;
	}
	if (sign == -1)
		ret *= -1;
	if (ret < -2147483648 || ret > 2147483647)
		ft_print_error();
	return ((int)ret);
}
