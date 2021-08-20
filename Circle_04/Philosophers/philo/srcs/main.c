/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:09:19 by afoulqui          #+#    #+#             */
/*   Updated: 2021/08/04 16:25:36 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_liveness(void *ptr)
{
	t_philo	*philo;
	long	time;

	philo = (t_philo *)ptr;
	time = 0;
	while (philo->table->stop == FALSE)
	{
		ft_sleep(philo->table->data[T_DIE] + 1);
		pthread_mutex_lock(&philo->table->checker);
		time = get_time() - philo->start_time;
		if ((philo->table->stop == FALSE)
			&& (time >= (long)philo->table->data[T_DIE]))
			display(philo, DEAD);
		pthread_mutex_unlock(&philo->table->checker);
	}
	return (NULL);
}

int	init_thread(t_table *table)
{
	int			i;
	pthread_t	thread;

	table->saved_time = get_time();
	i = 0;
	while (i < table->data[N_PHI])
	{
		if (pthread_create(&thread, NULL, &routine, (void *)&table->philo[i]))
			return (1);
		if (pthread_create(&table->philo[i].checker_thread, NULL,
				&check_liveness, (void *)&table->philo[i]))
			return (1);
		pthread_detach(thread);
		i++;
	}
	i = 0;
	while (i < table->data[N_PHI])
	{
		pthread_join(table->philo[i].checker_thread, NULL);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_table		table;

	if (parse(argc, argv, &table))
	{
		clear_all(&table);
		return (-1);
	}
	if (init_thread(&table))
	{
		clear_all(&table);
		return (-1);
	}
	clear_all(&table);
	return (0);
}
