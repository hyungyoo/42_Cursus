/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isformat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:24:49 by seyun             #+#    #+#             */
/*   Updated: 2021/11/08 13:29:33 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isformat(char *str, char *format)
{
	int	len_str;
	int len_format;
	char *fmt_str;

	len_str = ft_strlen(str);
	len_format = ft_strlen(format);
	if (len_str <= len_format)
		return (0);
	fmt_str = str + len_str - len_format;
	if (ft_strcmp(fmt_str, format) == 0)
		return (1);
	return (0);
}
