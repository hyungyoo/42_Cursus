/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:31:37 by hyungyoo          #+#    #+#             */
/*   Updated: 2022/07/06 20:48:36 by hyungyoo         ###   ########.fr       */
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

int ft_flag_eat(t_info *all, int flag)
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

void	ft_all_eat_checker(t_info *all, int *num_eat)
{
	int	i;

	i = -1;
	while (all->limit_eat != -1 && ++i < all->num_philo)
	{
		if (ft_count_eat(&(all->philo[i]), READ) >= all->limit_eat)
			(*num_eat) += 1;
	}
	if (*num_eat == all->num_philo)
		ft_flag_eat(all, WRITE);
}

void	ft_loop_checker(t_info *all)
{
	int	i;
	int	num_eat;

	i = -1;
	while (++i < all->num_philo)
		ft_mutex_eat(&((all->philo)[i]));
	while (!(all->flag_eat))
	{
		num_eat = 0;
		i = -1;
		while (++i < all->num_philo && !(ft_flag_die(all, READ)))
		{
			pthread_mutex_lock(&(all->checker));
			if (ft_get_time() - all->philo[i].last_eat > all->time_death)
			{
				ft_display(all->philo[i].id, "died", all);
				ft_flag_die(all, WRITE);
			}
			pthread_mutex_unlock(&(all->checker));
		}
		if (ft_flag_die(all, READ))
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
        pthread_mutex_destroy(&(all->philo[i].m_count_eat));
		i++;
	}
	pthread_mutex_destroy(&(all->msg));
	pthread_mutex_destroy(&(all->die));
	pthread_mutex_destroy(&(all->eat));
	pthread_mutex_destroy(&(all->m_flag_eat));
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
