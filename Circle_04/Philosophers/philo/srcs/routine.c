/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:30:19 by afoulqui          #+#    #+#             */
/*   Updated: 2021/08/19 16:45:13 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeping_thinking(t_philo *philo)
{
	display(philo, SLEEP);
	ft_sleep(philo->table->data[T_SLEEP]);
	display(philo, THINK);
}

void	check_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->checker);
	philo->table->meals++;
	philo->nb_meals++;
	if (philo->table->meals == philo->table->data[N_PHI])
		display(philo, END);
	pthread_mutex_unlock(&philo->table->checker);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->l_frk);
	display(philo, FORK);
	if (!philo->r_frk)
	{
		ft_sleep(philo->table->data[T_EAT] * 2);
		return ;
	}
	pthread_mutex_lock(philo->r_frk);
	philo->nb_meals++;
	display(philo, FORK);
	display(philo, EAT);
	philo->start_time = get_time();
	ft_sleep(philo->table->data[T_EAT]);
	pthread_mutex_unlock(philo->r_frk);
	pthread_mutex_unlock(philo->l_frk);
}

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		ft_sleep(philo->table->data[T_EAT] / 10);
	while (philo->table->stop == FALSE)
	{
		eating(philo);
		if (philo->nb_meals == philo->table->data[LIMIT_MEAL])
			check_meals(philo);
		if (philo->table->stop == FALSE)
			sleeping_thinking(philo);
	}
	return (NULL);
}
