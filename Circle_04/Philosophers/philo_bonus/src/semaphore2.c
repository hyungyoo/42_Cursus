/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:46:33 by hyungyoo          #+#    #+#             */
/*   Updated: 2022/07/11 19:51:26 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_loop_checker(void *phi)
{
	t_info	*all;
	t_philo	*philo;

	philo = (t_philo *)phi;
	all = philo->all;
	while (!ft_flag_die(philo, READ))
	{
		sem_wait(all->checker);
		if ((ft_get_time() - philo->last_eat) > all->time_death)
		{
			ft_close_checker(philo);
		}
		sem_post(all->checker);
		usleep(1000);
		if (all->limit_eat != -1
			&& ft_flag_eat_count(philo, READ) >= all->limit_eat)
			break ;
	}
	return (NULL);
}

void	ft_monitor_philo(t_philo *philo)
{
	t_info	*all;

	all = philo->all;
	if (pthread_mutex_init(&(philo->m_die), NULL))
		return ;
	if (pthread_mutex_init(&(philo->m_eat), NULL))
		return ;
	pthread_create(&(philo->loop_thread), NULL, ft_loop_checker, (void *)philo);
	if (philo->id % 2)
		usleep(15000);
	while (!(ft_flag_die(philo, READ))
		&& !(all->limit_eat != -1
			&& ft_flag_eat_count(philo, READ) >= all->limit_eat))
	{
		ft_eat(philo);
		ft_display(philo->id, "is sleeping", philo);
		ft_sleep(all->time_sleep, all->num_philo);
		ft_display(philo->id, "is thinking", philo);
	}
	pthread_join(philo->loop_thread, NULL);
	if (ft_flag_die(philo, READ))
		ft_close_checker(philo);
	ft_free_semaphore(philo->all);
	exit(0);
}

void	ft_waitpid_philo(t_info *all)
{
	int	i;
	int	ret;

	i = -1;
	while (++i < all->num_philo)
	{
		waitpid(-1, &ret, 0);
		if (ret != 0)
		{
			i = -1;
			while (++i < all->num_philo)
				kill((all->philo)[i].philo_pid, 15);
			ft_free_semaphore(all);
			break ;
		}
	}
	ft_free_semaphore(all);
	if (ret == 0)
		printf("all philosophers have eaten\n");
}

int	ft_create_process(t_info *all)
{
	int			i;

	i = -1;
	all->time_start = ft_get_time();
	while (++i < all->num_philo)
	{
		(all->philo)[i].philo_pid = fork();
		if ((all->philo)[i].philo_pid < 0)
			return (0);
		if ((all->philo)[i].philo_pid == 0)
		{
			(all->philo)[i].last_eat = ft_get_time();
			ft_monitor_philo(&((all->philo)[i]));
		}
	}
	return (1);
}

void	ft_semaphore(t_info *all)
{
	if (!(ft_create_process(all)))
		printf("Error fork\n");
	ft_waitpid_philo(all);
}
