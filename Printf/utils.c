/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:33:46 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/02/16 03:05:44 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_init_flag(t_flag *flag)
{
	flag->type = 0;
	flag->precision = -1;
	flag->negative = 0;
	flag->width = 0;
	flag->zero = 0;
	flag->base = 10;
	flag->sign = 1;
}

int				ft_putchar_static(char c, int target)
{
	static int		ret;
	static int		flag;

	if (flag == 1)
	{
		flag = 0;
		ret = 0;
	}
	if (target == 1)
	{
		flag = 1;
		return (ret);
	}
	ft_putchar_fd(c, 1);
	ret++;
	return (0);
}

int				ft_nbrlen(unsigned long long nbr, t_flag *flag)
{
	int		i;

	if (nbr == 0 && flag->precision != 0)
		return (1);
	i = 0;
	while (nbr)
	{
		i++;
		nbr /= flag->base;
	}
	return (i);
}

char			*ft_baseset(char type)
{
	if (type == 'u' || type == 'd' || type == 'i')
		return ("0123456789");
	else if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	else if (type == 'X')
		return ("0123456789ABCDEF");
	return (0);
}
