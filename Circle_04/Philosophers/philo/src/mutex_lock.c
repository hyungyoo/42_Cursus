/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_lock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:47:54 by hyungyoo          #+#    #+#             */
/*   Updated: 2022/07/06 21:48:39 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_flag_die(t_info *all, int flag)
{
	int	ret;

	ret = 0;
	if (flag == WRITE)
	{
		pthread_mutex_lock(&(all->die));
		all->flag_die = 1;
		pthread_mutex_unlock(&(all->die));
	}
	else
	{
		pthread_mutex_lock(&(all->die));
		if (all->flag_die == 1)
			ret = 1;
		pthread_mutex_unlock(&(all->die));
	}
	return (ret);
}

int	ft_flag_eat(t_info *all, int flag)
{
	int	ret;

	ret = 0;
	if (flag == WRITE)
	{
		pthread_mutex_lock(&(all->m_flag_eat));
		all->flag_eat = 1;
		pthread_mutex_unlock(&(all->m_flag_eat));
	}
	else
	{
		pthread_mutex_lock(&(all->m_flag_eat));
		if (all->flag_eat == 1)
			ret = 1;
		pthread_mutex_unlock(&(all->m_flag_eat));
	}
	return (ret);
}

int	ft_count_eat(t_philo *philo, int flag)
{
	int	ret;

	ret = 0;
	if (flag == WRITE)
	{
		pthread_mutex_lock(&(philo->m_count_eat));
		philo->count_eat += 1;
		pthread_mutex_unlock(&(philo->m_count_eat));
	}
	else
	{
		pthread_mutex_lock(&(philo->m_count_eat));
		ret = philo->count_eat;
		pthread_mutex_unlock(&(philo->m_count_eat));
	}
	return (ret);
}

void	ft_mutex_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->all->eat));
	philo->last_eat = ft_get_time();
	pthread_mutex_unlock(&(philo->all->eat));
}
