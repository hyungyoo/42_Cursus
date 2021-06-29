/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:00:58 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/02/16 13:42:30 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *str, ...)
{
	int			num_str;
	va_list		ap;

	va_start(ap, str);
	ft_parsing_str(ap, (char*)str);
	va_end(ap);
	num_str = ft_putchar_static(' ', 1);
	return (num_str);
}

int			ft_parsing_str(va_list ap, char *str)
{
	int			i;
	t_flag		*flag;

	i = 0;
	if (!(flag = (t_flag*)malloc(sizeof(t_flag))))
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_init_flag(flag);
			while (str[++i] && !(ft_strchr(CONVERSION, str[i])))
				ft_check_flag(ap, str, flag, i);
			flag->type = str[i];
			if ((flag->negative == 1
			|| flag->precision > -1) && flag->type != '%')
				flag->zero = 0;
			ft_controleur_type(ap, flag);
		}
		else
			ft_putchar_static(str[i], 0);
		i++;
	}
	free(flag);
	return (0);
}

void		ft_check_flag(va_list ap, char *str, t_flag *flag, int i)
{
	if (str[i] == '0' && flag->width == 0 && flag->precision == -1)
		flag->zero = 1;
	else if (str[i] == '-')
		flag->negative = 1;
	else if (str[i] == '.')
		flag->precision = 0;
	else if (ft_isdigit(str[i]) || str[i] == '*')
		ft_check_width_precision(ap, str, flag, i);
}

void		ft_check_width_precision(va_list ap, char *str, t_flag *flag, int i)
{
	if (ft_isdigit(str[i]))
	{
		if (flag->precision == -1)
			flag->width = flag->width * 10 + str[i] - 48;
		else
			flag->precision = flag->precision * 10 + str[i] - 48;
	}
	else if (str[i] == '*')
	{
		if (flag->precision == -1)
		{
			flag->width = va_arg(ap, int);
			if (flag->width < 0)
			{
				flag->negative = 1;
				flag->width *= -1;
			}
		}
		else
			flag->precision = va_arg(ap, int);
	}
}

void		ft_controleur_type(va_list ap, t_flag *flag)
{
	char		type;

	type = flag->type;
	if (type == 'c')
		ft_print_char(va_arg(ap, int), flag);
	else if (type == '%')
		ft_print_char('%', flag);
	else if (type == 's')
		ft_print_str(va_arg(ap, char*), flag);
	else if (type == 'p')
		ft_print_nbr(va_arg(ap, unsigned long long), flag);
	else if (type == 'd' || type == 'i')
		ft_print_nbr(va_arg(ap, int), flag);
	else if (type == 'x' || type == 'X' || type == 'u')
		ft_print_nbr(va_arg(ap, unsigned int), flag);
}
