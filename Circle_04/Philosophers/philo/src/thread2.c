/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:31:46 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/24 14:25:47 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_eat_1(t_philo *philo)
{
	t_info	*all;

	all = philo->all;
	pthread_mutex_lock(&(all->fork[philo->l_fork]));
	ft_display(philo->id, "has taken a fork", all);
	if (philo->l_fork == philo->r_fork)
	{
		ft_sleep(all->time_death * 2);
		return ;
	}
	pthread_mutex_lock(&(all->fork[philo->r_fork]));
	ft_display(philo->id, "has taken a fork", all);
	pthread_mutex_lock(&(all->checker));
	ft_display(philo->id, "is eating", all);
	philo->last_eat = ft_get_time();
	pthread_mutex_unlock(&(all->checker));
	philo->count_eat += 1;
	ft_sleep(all->time_eat);
	pthread_mutex_unlock(&(all->fork[philo->l_fork]));
	pthread_mutex_unlock(&(all->fork[philo->r_fork]));
}

void	ft_eat_2(t_philo *philo)
{
	t_info	*all;

	all = philo->all;
	if ((philo->id) % 2 == 1)
		pthread_mutex_lock(&(all->fork[philo->l_fork]));
	else
		pthread_mutex_lock(&(all->fork[philo->r_fork]));
	ft_display(philo->id, "has taken a fork", all);
	if (philo->l_fork == philo->r_fork)
	{
		ft_sleep(all->time_death * 2);
		return ;
	}
	if ((philo->id) % 2 == 1)
		pthread_mutex_lock(&(all->fork[philo->r_fork]));
	else
		pthread_mutex_lock(&(all->fork[philo->l_fork]));
	ft_display(philo->id, "has taken a fork", all);
}

void	ft_eat_3(t_philo *philo)
{
	t_info	*all;

	all = philo->all;
	pthread_mutex_lock(&(all->checker));
	ft_display(philo->id, "is eating", all);
	philo->last_eat = ft_get_time();
	pthread_mutex_unlock(&(all->checker));
	philo->count_eat += 1;
	ft_sleep(all->time_eat);
	pthread_mutex_unlock(&(all->fork[philo->l_fork]));
	pthread_mutex_unlock(&(all->fork[philo->r_fork]));
}

void	ft_sleep_think(t_philo *philo)
{
	t_info	*all;

	all = philo->all;
	ft_display(philo->id, "is sleeping", all);
	ft_sleep(all->time_sleep);
	ft_display(philo->id, "is thinking", all);
}

void	*ft_philo(void *philo_ptr)
{
	t_philo	*philo;
	t_info	*all;

	philo = (t_philo *)philo_ptr;
	all = philo->all;
	if (philo->id % 2)
		usleep(15000);
	while (!(all->flag_die))
	{
		if (all->num_philo % 2 == 1)
			ft_eat_1(philo);
		else
		{
			ft_eat_2(philo);
			ft_eat_3(philo);
		}
		if (all->flag_eat == 1)
			break ;
		ft_sleep_think(philo);
	}
	return (NULL);
}
