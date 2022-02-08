/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isformat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:09:48 by hyungyoo          #+#    #+#             */
/*   Updated: 2022/01/25 15:03:49 by ytak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isformat(char *str, char *format)
{
	int		len_str;
	int		len_format;
	char	*fmt_str;

	len_str = ft_strlen(str);
	len_format = ft_strlen(format);
	if (len_str <= len_format)
		return (0);
	fmt_str = str + len_str - len_format;
	if (ft_strcmp(fmt_str, format) == 0)
		return (1);
	return (0);
}
