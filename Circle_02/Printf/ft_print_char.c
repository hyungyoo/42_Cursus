/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 01:14:00 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/02/16 03:55:23 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_print_char(int c, t_flag *flag)
{
	if (flag->type == '%' && flag->negative == 1)
		flag->zero = 0;
	if (flag->negative == 1)
		ft_putchar_static(c, 0);
	ft_put_width(flag->width, 1, flag->zero);
	if (flag->negative == 0)
		ft_putchar_static(c, 0);
}

void			ft_put_width(int width, int len, int zero)
{
	while (len < width)
	{
		if (zero == 1)
			ft_putchar_static('0', 0);
		else
			ft_putchar_static(' ', 0);
		len++;
	}
}
