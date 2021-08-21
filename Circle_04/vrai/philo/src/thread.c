/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:31:37 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/21 19:31:10 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_all_eat_checker(t_info *all, int *num_eat)
{
	int	i;

	i = -1;
	while (all->limit_eat != -1 && ++i < all->num_philo)
	{
		if (all->philo[i].count_eat >= all->limit_eat)
			(*num_eat) += 1;
	}
	if (*num_eat == all->num_philo)
		all->flag_eat = 1;
}

void	ft_loop_checker(t_info *all)
{
	int	i;
	int	num_eat;

	i = -1;
	while (++i < all->num_philo)
		all->philo[i].last_eat = ft_get_time();
	while (!(all->flag_eat))
	{
		num_eat = 0;
		i = -1;
		while (++i < all->num_philo && !(all->flag_die))
		{
			pthread_mutex_lock(&(all->checker));
			if (ft_get_time() - all->philo[i].last_eat > all->time_death)
			{
				ft_display(all->philo[i].id, "died", all);
				all->flag_die = 1;
			}
			pthread_mutex_unlock(&(all->checker));
		}
		if (all->flag_die == 1)
			break ;
		ft_all_eat_checker(all, &num_eat);
	}
}

int	ft_create_thread(t_info *all)
{
	int			i;

	i = -1;
	all->time_start = ft_get_time();
	while (++i < all->num_philo)
	{
		if (pthread_create(&(all->philo[i].thread_id), NULL,
				&ft_philo, (void*)&(all->philo[i])))
			return (ft_print_error("Error create thread"));
	}
	return (1);
}

void	ft_free_thread(t_info *all)
{
	int	i;

	i = 0;
	while (i < all->num_philo)
	{
		pthread_join(all->philo[i].thread_id, NULL);
		pthread_mutex_destroy(&(all->fork[i]));
		i++;
	}
	pthread_mutex_destroy(&(all->msg));
	pthread_mutex_destroy(&(all->checker));
}

void	ft_thread(t_info *all)
{
	if (!(ft_create_thread(all)))
		return ;
	ft_loop_checker(all);
	ft_free_thread(all);
	if (!(all->flag_die))
		printf("all philosophers have eaten\n");
}
