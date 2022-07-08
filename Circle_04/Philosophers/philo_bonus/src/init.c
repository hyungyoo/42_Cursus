/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:46:09 by hyungyoo          #+#    #+#             */
/*   Updated: 2022/07/08 03:30:59 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_init_info(t_info *all)
{
	all->flag_eat = 0;
	all->time_start = 0;
	all->philo = NULL;
	all->fork = NULL;
}

int	ft_init_philo(t_info *all)
{
	int	i;

	i = 0;
	all->philo = (t_philo *)malloc(sizeof(t_philo) * (all->num_philo));
	if (!(all->philo))
		return (ft_print_error("Error malloc"));
	while (i < all->num_philo)
	{
		all->philo[i].id = i;
		all->philo[i].count_eat = 0;
		all->philo[i].last_eat = 0;
		all->philo[i].flag_die = 0;
		all->philo[i].all = all;
		i++;
	}
	return (1);
}

int	ft_init_semaphore(t_info *all)
{
	sem_unlink("/philo_forks");
	sem_unlink("/philo_msg");
	sem_unlink("/philo_checker");
	all->fork = sem_open("/philo_forks", O_CREAT, S_IRWXU, all->num_philo);
	all->msg = sem_open("/philo_msg", O_CREAT, S_IRWXU, 1);
	all->checker = sem_open("/philo_checker", O_CREAT, S_IRWXU, 1);
	return (1);
}

int	ft_init(int argc, char **argv, t_info *all)
{
	if (!(ft_arg(argc, argv)))
		return (0);
	if (!(ft_init_all1(argc, argv, all)))
		return (0);
	if (!(ft_init_all2(argv, all)))
		return (0);
	ft_init_info(all);
	if (!(ft_init_philo(all)))
		return (0);
	if (!(ft_init_semaphore(all)))
		return (0);
	return (1);
}
