/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:04:51 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/12 13:07:06 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_dquote(char *str)
{
	int	i;
	int	num_dquote;

	num_dquote = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == 34)
			num_dquote++;
		i++;
	}
	return (num_dquote % 2);
}

int	ft_quote(char *str)
{
	int	i;
	int	num_quote;

	num_quote = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == 39)
			num_quote++;
		i++;
	}
	return (num_quote % 2);
}

int	ft_verifier_quote(char c)
{
	if (c == 34)
		return (34);
	else if (c == 39)
		return (39);
	else
		return (0);
}
