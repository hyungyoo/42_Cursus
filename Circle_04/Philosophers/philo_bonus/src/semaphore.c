/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:46:33 by hyungyoo          #+#    #+#             */
/*   Updated: 2022/07/11 19:51:07 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_flag_die(t_philo *philo, int flag)
{
	int	ret;

	ret = 0;
	if (flag == WRITE)
	{
		pthread_mutex_lock(&(philo->m_die));
		philo->flag_die = 1;
		pthread_mutex_unlock(&(philo->m_die));
	}
	else
	{
		pthread_mutex_lock(&(philo->m_die));
		if (philo->flag_die == 1)
			ret = 1;
		pthread_mutex_unlock(&(philo->m_die));
	}
	return (ret);
}

int	ft_flag_eat_count(t_philo *philo, int flag)
{
	int	ret;

	ret = 0;
	if (flag == WRITE)
	{
		pthread_mutex_lock(&(philo->m_eat));
		philo->count_eat += 1;
		pthread_mutex_unlock(&(philo->m_eat));
	}
	else
	{
		pthread_mutex_lock(&(philo->m_eat));
		if (philo->count_eat)
			ret = philo->count_eat;
		pthread_mutex_unlock(&(philo->m_eat));
	}
	return (ret);
}

void	ft_eat(t_philo *philo)
{
	t_info	*all;

	all = philo->all;
	sem_wait(all->fork);
	ft_display(philo->id, "has taken a fork", philo);
	sem_wait(all->fork);
	ft_display(philo->id, "has taken a fork", philo);
	sem_wait(all->checker);
	philo->last_eat = ft_get_time();
	sem_post(all->checker);
	ft_display(philo->id, "is eating", philo);
	ft_sleep(all->time_eat, all->num_philo);
	ft_flag_eat_count(philo, WRITE);
	sem_post(all->fork);
	sem_post(all->fork);
}

void	ft_free_semaphore(t_info *all)
{
	usleep(150000);
	sem_close(all->msg);
	sem_close(all->fork);
	sem_close(all->checker);
	sem_unlink("/philo_forks");
	sem_unlink("/philo_msg");
	sem_unlink("/philo_checker");
}

void	ft_close_checker(t_philo *philo)
{
	t_info	*all;

	all = philo->all;
	ft_display(philo->id, "died", philo);
	sem_post(all->checker);
	ft_free_semaphore(all);
	pthread_join(philo->loop_thread, NULL);
	exit(1);
}
