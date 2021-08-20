/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:57:17 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/20 20:02:57 by hyungyoo         ###   ########.fr       */
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

void	ft_init_all(int argc, char **argv, t_info *all)
{
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) > 0)
			all->limit_eat = ft_atoi(argv[5]);
		else
			ft_print_error("Error value of limit_eat");
	}
	else
		all->limit_eat = -1;
	if (ft_atoi(argv[1]) > 0)
		all->num_philo = ft_atoi(argv[1]);
	else
		ft_print_error("Error value of number of Philosophers");
	if (ft_atoi(argv[2]) > 0)
		all->time_death = ft_atoi(argv[2]);
	else
		ft_print_error("Error value of time_death");
	if (ft_atoi(argv[3]) > 0)
		all->time_eat = ft_atoi(argv[3]);
	else
		ft_print_error("Error value of time_eat");
	if (ft_atoi(argv[4]) > 0)
		all->time_sleep = ft_atoi(argv[4]);
	else
		ft_print_error("Error value of time_sleep");
}

void	ft_init_info(t_info *all)
{
	all->flag_eat = 0;
	all->flag_die = 0;
	all->time_start = 0;
	all->philo = NULL;
	all->fork = NULL;
}

void	ft_init_philo(t_info *all)
{
	int	i;

	i = 0;
	all->philo = (t_philo *)malloc(sizeof(t_philo) * (all->num_philo));
	if (!(all->philo))
		ft_print_error("Error malloc");
	while (i < all->num_philo)
	{
		all->philo[i].id = i;
		all->philo[i].count_eat = 0;
		all->philo[i].l_fork = i;
		all->philo[i].r_fork = (i + 1) % all->num_philo;
		all->philo[i].last_eat = 0;
		all->philo[i].all = all;
		i++;
	}
}

void	ft_init_mutex(t_info *all)
{
	int	i;

	i = 0;
	all->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* all->num_philo);
	if (!(all->fork))
		return ;
	while (i < all->num_philo)
	{
		if (pthread_mutex_init(&(all->fork[i]), NULL))
			ft_print_error("Error initialize mutex");
		i++;
	}
	if (pthread_mutex_init(&(all->msg), NULL))
		ft_print_error("Error initialize mutex");
	if (pthread_mutex_init(&(all->checker), NULL))
		ft_print_error("Error initialize mutex");
}

void	ft_init(int argc, char **argv, t_info *all)
{
	ft_arg(argc, argv);
	ft_init_all(argc, argv, all);
	ft_init_info(all);
	ft_init_philo(all);
	ft_init_mutex(all);
}
