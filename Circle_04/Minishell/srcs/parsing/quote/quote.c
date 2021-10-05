/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:06:00 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/05 14:40:53 by hyungyoo         ###   ########.fr       */
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
	return (num_dquote);
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
	return (num_quote);
}
/*
int	ft_verifier_ordre(char *str)
{
	int	first_quote;
	int	last_quote;
	int	first_dquote;
	int last_dquote;

	// "로 시작한다면, "로 끝나거나, 마무리가되어야함
	// '로 시작한다면, '로 끝나거나, 마무리가되어야함
	return (0);
}
*/
int	ft_verifier_dquote(char *str)
{
	int	num_dquote;
	int	num_quote;

	num_dquote = 0;
	num_quote = 0;
	num_dquote = ft_dquote(str);
	num_quote = ft_quote(str);
	if (num_quote % 2)
		ft_putstr("Error: quote\n");
	else if (num_dquote % 2)
		ft_putstr("Error: dquote\n");
	return (0);
}
/*
int ft_verifier_dquote(char *str)
{
	to do:
		1. 첫번재가 "라면,
		"로 닫히는지? 짝수인지? 
		2. 첫번쨰가 '라면,
		'로 닫히는지? 짝수인지?
}
*/
