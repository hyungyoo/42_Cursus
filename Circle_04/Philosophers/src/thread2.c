/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:48:18 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/20 23:38:00 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_eat(t_philo *philo)
{
	t_info	*all;

	all = philo->all;
	pthread_mutex_lock(&(all->fork[philo->l_fork]));
	ft_display(philo->id, "has taken a fork", all);
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
		usleep(all->time_eat * 2);
	while (!(all->flag_die))
	{
		ft_eat(philo);
		if (all->flag_eat == 1)
			break ;
		ft_sleep_think(philo);
	}
	return (NULL);
}
