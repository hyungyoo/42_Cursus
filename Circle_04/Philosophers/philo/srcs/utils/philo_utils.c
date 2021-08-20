/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:22:43 by afoulqui          #+#    #+#             */
/*   Updated: 2021/08/06 15:23:39 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_time(void)
{
	struct timeval	now;
	long int		now_int;

	gettimeofday(&now, NULL);
	now_int = (now.tv_sec * 1000) + (now.tv_usec / 1000);
	return (now_int);
}

void	ft_sleep(int time_sleep)
{
	long int	time;

	time = get_time();
	while ((get_time() - time) < time_sleep)
		usleep(time_sleep / 10);
}

void	clear_all(t_table *table)
{
	int	i;

	pthread_mutex_destroy(&table->msg);
	pthread_mutex_destroy(&table->checker);
	i = 0;
	while (i < table->data[N_PHI])
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	free(table->forks);
	free(table->philo);
}
