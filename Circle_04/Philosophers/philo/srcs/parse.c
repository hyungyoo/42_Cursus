/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:20:10 by afoulqui          #+#    #+#             */
/*   Updated: 2021/08/05 12:22:19 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philo(t_table *table)
{
	t_philo	*philo;
	int		i;

	philo = malloc(sizeof(t_philo) * table->data[N_PHI]);
	if (!philo)
		return (NULL);
	i = 0;
	while (i < table->data[N_PHI])
	{
		philo[i].id = i + 1;
		philo[i].nb_meals = 0;
		philo[i].l_frk = &table->forks[i];
		philo[i].r_frk = &table->forks[(i + 1) % table->data[N_PHI]];
		philo[i].table = table;
		i++;
	}
	return (philo);
}

int	init_mutex(t_table *table)
{
	int		i;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->data[N_PHI]);
	if (!table->forks)
		return (1);
	i = 0;
	while (i < table->data[N_PHI])
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&table->msg, NULL);
	pthread_mutex_init(&table->checker, NULL);
	return (0);
}

static int	print_return(char *err_msg)
{
	write(2, "ERROR : ", 9);
	write(2, err_msg, ft_strlen(err_msg));
	write(2, "\n.", 3);
	return (1);
}

int	parse(int argc, char **argv, t_table *table)
{
	if (argc < 5 || argc > 6)
		return (print_return("wrong number of arguments"));
	if (ft_onlydigit(argv) == FALSE)
		return (print_return("only numbers are accepted as arguments"));
	table->data[N_PHI] = ft_atoi(argv[1]);
	if (table->data[N_PHI] < 1)
		return (print_return("not enough philosophers"));
	table->data[T_DIE] = ft_atoi(argv[2]);
	table->data[T_EAT] = ft_atoi(argv[3]);
	table->data[T_SLEEP] = ft_atoi(argv[4]);
	if (argc == 6 && argv[5] > 0)
		table->data[LIMIT_MEAL] = ft_atoi(argv[5]);
	else
		table->data[LIMIT_MEAL] = -1;
	table->meals = 0;
	table->stop = FALSE;
	if (init_mutex(table))
		return (1);
	table->philo = init_philo(table);
	if (table->philo == NULL)
		return (1);
	return (0);
}
