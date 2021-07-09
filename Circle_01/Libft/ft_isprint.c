/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 02:43:29 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/06/25 02:51:34 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// c에 해당하는 아스키코드값이 출력가능하면 1을, 아니면 0을 반환
//
#include "libft.h"

int	ft_isprint(int a)
{
	if (a > 31 && a < 127)
		return (1);
	else
		return (0);
}