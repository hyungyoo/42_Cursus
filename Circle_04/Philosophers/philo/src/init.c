/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:46:09 by hyungyoo          #+#    #+#             */
/*   Updated: 2022/07/06 21:46:10 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_init_info(t_info *all)
{
	all->flag_eat = 0;
	all->flag_die = 0;
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
		all->philo[i].l_fork = i;
		all->philo[i].r_fork = (i + 1) % all->num_philo;
		all->philo[i].last_eat = 0;
		all->philo[i].all = all;
		if (pthread_mutex_init(&(all->philo[i].m_count_eat), NULL))
		{
			return (ft_print_error("Error initialize mutex"));
		}
		i++;
	}
	return (1);
}

int	ft_init_mutex(t_info *all)
{
	int	i;

	i = 0;
	all->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* all->num_philo);
	if (!(all->fork))
		return (ft_print_error("Error malloc fork"));
	while (i < all->num_philo)
	{
		if (pthread_mutex_init(&(all->fork[i]), NULL))
			return (ft_print_error("Error initialize mutex"));
		i++;
	}
	if (pthread_mutex_init(&(all->msg), NULL))
		return (ft_print_error("Error initialize mutex"));
	if (pthread_mutex_init(&(all->checker), NULL))
		return (ft_print_error("Error initialize mutex"));
	if (pthread_mutex_init(&(all->die), NULL))
		return (ft_print_error("Error initialize mutex"));
	if (pthread_mutex_init(&(all->eat), NULL))
		return (ft_print_error("Error initialize mutex"));
	if (pthread_mutex_init(&(all->m_flag_eat), NULL))
		return (ft_print_error("Error initialize mutex"));
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
	if (!(ft_init_mutex(all)))
		return (0);
	return (1);
}
