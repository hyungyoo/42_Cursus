/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:25:54 by keulee            #+#    #+#             */
/*   Updated: 2019/12/18 15:04:17 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//
// ft_isalnum.c check if a is an alphabet or a number.
// If it's true it returns 1 or 0.
//
#include "libft.h"

int	ft_isalnum(int a)
{
	if ((a > 47 && a < 58) || (a > 64 && a < 91) || (a > 96 && a < 123))
		return (1);
	else
		return (0);
}
