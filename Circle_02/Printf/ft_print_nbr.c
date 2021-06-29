/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 00:46:29 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/02/16 07:41:54 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_nbr(unsigned long long nbr, t_flag *flag)
{
	char	*buf;
	int		buf_len;
	int		i;

	if (flag->type == 'x' || flag->type == 'X' || flag->type == 'p')
		flag->base = 16;
	if ((flag->type == 'd' || flag->type == 'i') && (int)nbr < 0)
	{
		flag->sign = -1;
		nbr = -nbr;
	}
	buf_len = ft_put_precision_str(nbr, flag, &buf);
	buf_len += ft_put_negative(flag, &buf);
	if (flag->type == 'p')
		buf_len = ft_put_pointeur(&buf);
	ft_put_width_str(&buf, flag);
	ft_put_negative2(buf_len, flag, &buf);
	i = 0;
	while (buf[i])
	{
		ft_putchar_static(buf[i], 0);
		i++;
	}
	free(buf);
}

int			ft_put_precision_str(unsigned long long nbr,
		t_flag *flag, char **buf)
{
	int		buf_len;
	int		ret;
	int		i;

	ret = ft_nbrlen(nbr, flag);
	buf_len = (flag->precision > ret) ? flag->precision : ret;
	if (!(*buf = (char*)malloc(sizeof(char) * buf_len + 1)))
		return (-1);
	i = 0;
	(*buf)[buf_len] = '\0';
	while (ret + i < buf_len)
	{
		(*buf)[i] = '0';
		i++;
	}
	i = 1;
	if (nbr == 0 && flag->precision != 0)
		(*buf)[buf_len - i] = '0';
	while (nbr)
	{
		(*buf)[buf_len - i] = ft_baseset(flag->type)[nbr % flag->base];
		nbr /= flag->base;
		i++;
	}
	return (ret);
}

int			ft_put_negative(t_flag *flag, char **buf)
{
	int		len_add;

	len_add = 0;
	if ((flag->type == 'i' || flag->type == 'd') &&
			flag->zero == 0 && flag->sign == -1)
	{
		*buf = ft_strjoin_target("-", *buf, 2);
		len_add = 1;
	}
	return (len_add);
}

void		ft_put_negative2(int buf_len, t_flag *flag, char **buf)
{
	if (flag->sign == -1 && flag->zero == 1)
	{
		if (buf_len >= flag->width)
			*buf = ft_strjoin_target("-", *buf, 2);
		else if (buf_len < flag->width)
			*buf[0] = '-';
	}
}

int			ft_put_pointeur(char **buf)
{
	*buf = ft_strjoin_target("0x", *buf, 2);
	return (ft_strlen(*buf));
}
