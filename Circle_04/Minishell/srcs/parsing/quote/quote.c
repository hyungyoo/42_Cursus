/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:06:00 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/11 15:50:39 by hyungyoo         ###   ########.fr       */
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

char	get_first(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_verifier_quote(str[i]))
			return (str[i]);
		i++;
	}
	return ('\0');
}

char	get_last(char *str)
{
	char	last;
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (ft_verifier_quote(str[i]) && !flag)
		{
			flag++;
		}
		else if (ft_verifier_quote(str[i]) && flag)
		{
			last = str[i];
		}
		i++;
	}
	return (last);
}

int	ft_num_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_verifier_quote(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_verifier_dquote(char *str)
{
	char	first_quote;
	char	last_quote;

	first_quote = 0;
	last_quote = 0;
	if (!ft_num_quote(str))
		return (0);
	first_quote = get_first(str);
	last_quote = get_last(str);
	//
	printf("cmd == %s first = %c, last %c\n",str,  first_quote, last_quote);
	//
	if (first_quote != last_quote)
	{
		if (first_quote == 39)
			ft_putstr("Error: quote\n");
		else if (first_quote == 34)
			ft_putstr("Error: dquote\n");
		return (1);
	}
	return (0);
}
