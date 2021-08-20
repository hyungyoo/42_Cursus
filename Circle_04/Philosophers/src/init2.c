/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:57:17 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/20 23:40:04 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_digit(char c)
{
	return ((c >= '0' && c <= '9'));
}

void	ft_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (!(argc == 5 || argc == 6))
	{
		ft_print_error("wrong number of arguments");
	}
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_digit(argv[i][j]))
			{
				if (argv[i][j] == '-')
					ft_print_error("Error : value must be more than 0");
				else
					ft_print_error("Error only number for arguments");
			}
			j++;
		}
		i++;
	}
}
