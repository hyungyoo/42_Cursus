/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 02:41:37 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/06/25 02:42:04 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// c값이 알파벳이나 숫자면 1을, 아니면 0을 반환
//
#include "libft.h"

int	ft_isalnum(int a)
{
	if ((a > 47 && a < 58) || (a > 64 && a < 91) || (a > 96 && a < 123))
		return (1);
	else
		return (0);
}