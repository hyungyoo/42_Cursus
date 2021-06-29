/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 01:57:40 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/02/16 07:33:08 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_print_str(char *str, t_flag *flag)
{
	char	*buf;
	int		i;

	if (str == NULL)
		str = "(null)";
	if (flag->precision == -1 || (size_t)flag->precision > ft_strlen(str))
		flag->precision = ft_strlen(str);
	ft_parsing_buf(&buf, str, flag->precision, ft_strlen(str));
	ft_put_width_str(&buf, flag);
	i = 0;
	while (buf[i])
	{
		ft_putchar_static(buf[i], 0);
		i++;
	}
	free(buf);
}

/*
** PARSING STR ET RETURN COMME BUF POUR PRECISION
*/

int				ft_parsing_buf(char **buf, char *str, int end, int len)
{
	int		i;

	end = end < len ? end : len;
	if (!(*buf = (char*)malloc(sizeof(char) * end + 1)))
		return (-1);
	i = 0;
	while (i < end)
	{
		(*buf)[i] = str[i];
		i++;
	}
	(*buf)[i] = '\0';
	return (1);
}

/*
** POUR WIDTH SI WIDTH EST PLUS GRAND QUE STRLEN
*/

int				ft_put_width_str(char **str, t_flag *flag)
{
	char	*width;
	int		i;

	if (flag->width <= (int)ft_strlen(*str))
		return (1);
	if (!(width = (char*)malloc(sizeof(char) *
		(flag->width - ft_strlen(*str) + 1))))
		return (-1);
	i = 0;
	while ((size_t)i < flag->width - ft_strlen(*str))
	{
		width[i] = (flag->zero == 1) ? '0' : ' ';
		i++;
	}
	width[i] = '\0';
	if (flag->negative == 0)
		*str = ft_strjoin_target(width, *str, 3);
	else if (flag->negative == 1)
		*str = ft_strjoin_target(*str, width, 3);
	return (1);
}

/*
** FUNSTION POUR FREE WIDTH ET BUF
*/

char			*ft_strjoin_target(char *s1, char *s2, int free_target)
{
	char	*result;
	int		i;
	int		j;
	int		s1_len;
	int		s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!result)
		return (0);
	i = -1;
	while (++i < s1_len)
		result[i] = s1[i];
	if (free_target == 1 || free_target == 3)
		free(s1);
	j = 0;
	while (j < s2_len)
		result[i++] = s2[j++];
	if (free_target == 2 || free_target == 3)
		free(s2);
	result[i] = 0;
	return (result);
}
