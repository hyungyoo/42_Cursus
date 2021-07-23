/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:57:50 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/07/22 14:57:51 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int	ft_digit(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

/*
 *	si num est numero ou espace, envoie 1,
 *	si num n'est pas numero ni esapace, envoie 0
 */

int	ft_verifier_argv(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (!(num[i] == ' ' || num[i] == '-' || ft_digit(num[i])))
			return (1);
		else if (num[i] == '-')
			if (!ft_digit(num[i + 1]))
				return (1);
		i++;
	}
	return (0);
}

int	ft_verifier_split(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (num[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_duplicate(t_stack *stack)
{
	t_stack	*new;

	new = stack->prev;
	while (stack != new)
	{
		if (new->num == stack->num)
			return (1);
		stack = stack->next;
	}
	return (0);
}
