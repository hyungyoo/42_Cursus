/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:28:00 by hyungyoo          #+#    #+#             */
/*   Updated: 2022/07/06 22:09:53 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_mutex_lock_fork(t_philo *philo, t_info *all, int first_second)
{	
	if ((philo->id) % 2 == first_second)
		pthread_mutex_lock(&(all->fork[philo->l_fork]));
	else
		pthread_mutex_lock(&(all->fork[philo->r_fork]));
	ft_display(philo->id, "has taken a fork", all);
}

void	ft_mutex_unlock_fork(t_info *all, t_philo *philo, int philo_id)
{
	if (philo_id % 2 == 1)
	{
		pthread_mutex_unlock(&(all->fork[philo->l_fork]));
		pthread_mutex_unlock(&(all->fork[philo->r_fork]));
	}
	else
	{
		pthread_mutex_unlock(&(all->fork[philo->r_fork]));
		pthread_mutex_unlock(&(all->fork[philo->l_fork]));
	}
}

void	ft_eat(t_philo *philo)
{
	t_info	*all;

	all = philo->all;
	ft_mutex_lock_fork(philo, all, FIRST);
	if (philo->l_fork == philo->r_fork)
	{
		pthread_mutex_unlock(&(all->fork[philo->l_fork]));
		ft_sleep(all->time_death * 2);
		return ;
	}
	ft_mutex_lock_fork(philo, all, SECOND);
	pthread_mutex_lock(&(all->checker));
	ft_display(philo->id, "is eating", all);
	ft_mutex_eat(philo);
	pthread_mutex_unlock(&(all->checker));
	ft_count_eat(philo, WRITE);
	ft_sleep(all->time_eat);
	ft_mutex_unlock_fork(all, philo, philo->id);
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
		usleep(400);
	while (!(ft_flag_die(all, READ)))
	{
		ft_eat(philo);
		if (ft_flag_eat(all, READ))
			break ;
		ft_sleep_think(philo);
	}
	return (NULL);
}
