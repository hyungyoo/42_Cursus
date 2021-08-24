/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:30:53 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/23 21:51:28 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	ft_digit(char c)
{
	return ((c >= '0' && c <= '9'));
}

int	ft_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (!(argc == 5 || argc == 6))
	{
		return (ft_print_error("wrong number of arguments"));
	}
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_digit(argv[i][j]))
			{
				if (argv[i][j] == '-')
					return (ft_print_error("Error : range of values"));
				else
					return (ft_print_error("Error only nbr for arg"));
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_init_all1(int argc, char **argv, t_info *all)
{
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) > 0)
			all->limit_eat = ft_atoi(argv[5]);
		else
			return (ft_print_error("Error value of limit_eat"));
	}
	else
		all->limit_eat = -1;
	if (ft_atoi(argv[1]) > 0)
		all->num_philo = ft_atoi(argv[1]);
	else
		return (ft_print_error("Error value of number of Philosophers"));
	return (1);
}

int	ft_init_all2(char **argv, t_info *all)
{
	if (ft_atoi(argv[2]) > 0)
		all->time_death = ft_atoi(argv[2]);
	else
		return (ft_print_error("Error value of time_death"));
	if (ft_atoi(argv[3]) > 0)
		all->time_eat = ft_atoi(argv[3]);
	else
		return (ft_print_error("Error value of time_eat"));
	if (ft_atoi(argv[4]) > 0)
		all->time_sleep = ft_atoi(argv[4]);
	else
		return (ft_print_error("Error value of time_sleep"));
	return (1);
}
