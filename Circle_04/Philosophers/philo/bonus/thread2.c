/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:31:46 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/24 13:32:06 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_eat(t_philo *philo)
{
	t_info	*all;

	all = philo->all;
	sem_wait(all->fork);
	ft_display(philo->id, "has taken a fork", all);
	sem_wait(all->fork);
	ft_display(philo->id, "has taken a fork", all);
	sem_wait(all->checker);
	ft_display(philo->id, "is eating", all);
	philo->last_eat = ft_get_time();
	sem_post(all->checker);
	philo->count_eat += 1;
	ft_sleep(all->time_eat);
	sem_post(all->fork);
	sem_post(all->fork);
}

void	ft_sleep_think(t_philo *philo)
{
	t_info	*all;

	all = philo->all;
	ft_display(philo->id, "is sleeping", all);
	ft_sleep(all->time_sleep);
	ft_display(philo->id, "is thinking", all);
}

void	*ft_philo(t_philo *philo_ptr)
{
	t_philo	*philo;
	t_info	*all;

	philo = philo_ptr;
	all = philo->all;
	if (philo->id % 2)
		usleep(15000);
	pthread_create(&(philo->thread_id), NULL, ft_loop_checker, (void *)philo);
	while (!(all->flag_die))
	{
		ft_eat(philo);
		if (all->flag_eat == 1)
			break ;
		ft_sleep_think(philo);
	}
	pthread_join(philo->thread_id, NULL);
	return (NULL);
}
