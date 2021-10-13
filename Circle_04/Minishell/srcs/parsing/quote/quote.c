/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:06:00 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/10/13 16:25:55 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

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

char	get_last(char *str, char first)
{
	char	last;
	int		i;
	int		flag;
	int		flag_pair;

	i = 0;
	flag = 0;
	last = 0;
	flag_pair = 0;
	while (str[i])
	{
		if (first == str[i])
			flag_pair++;
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
	if (flag_pair % 2)
		return (0);
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
	static char	first_quote;
	static char	last_quote;

	first_quote = 0;
	last_quote = 0;
	if (!ft_num_quote(str))
		return (0);
	first_quote = get_first(str);
	last_quote = get_last(str, first_quote);
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
