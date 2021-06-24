/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:32:11 by keulee            #+#    #+#             */
/*   Updated: 2019/12/18 15:09:11 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//
// Check if a is printable or not.
// If it's true, it returns 1 or 0.
//
#include "libft.h"

int	ft_isprint(int a)
{
	if (a > 31 && a < 127)
		return (1);
	else
		return (0);
}
