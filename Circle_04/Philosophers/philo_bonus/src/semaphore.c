/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:46:33 by hyungyoo          #+#    #+#             */
/*   Updated: 2022/07/08 05:30:01 by hyungyoo         ###   ########.fr       */
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
	ft_display(philo->id, "is eating", philo);
	sem_post(all->checker);
	ft_sleep(all->time_eat, all->num_philo);
	philo->count_eat++;
	sem_post(all->fork);
	sem_post(all->fork);
}

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
			ft_display(philo->id, "died", philo);
			ft_flag_die(philo, WRITE);
			//sem_post(all->checker);
			exit(1);
		}
		sem_post(all->checker);
		if (ft_flag_die(philo, READ))
			break ;
		usleep(1000);
		if (philo->count_eat != -1 && philo->count_eat >= all->limit_eat)
			break ;
	}
	return (NULL);
}

void	ft_free_semaphore(t_info *all)
{
	sem_close(all->fork);
	sem_close(all->msg);
	sem_close(all->checker);
	sem_unlink("/philo_forks");
	sem_unlink("/philo_msg");
	sem_unlink("/philo_checker");
}

void	ft_monitor_philo(t_philo *philo)
{
	t_info	*all;
	//int		ret;

	//ret = 1;
	all = philo->all;
	if (pthread_mutex_init(&(philo->m_die), NULL))
		return ;
	pthread_create(&(philo->loop_thread), NULL, ft_loop_checker, (void *)philo);
	if (philo->id % 2)
		usleep(15000);
	while (!(ft_flag_die(philo, READ)))
	{
		ft_eat(philo);
		if (all->limit_eat != -1 && philo->count_eat >= all->limit_eat)
			break ;
		if (ft_flag_die(philo, READ))
			break ;
		ft_display(philo->id, "is sleeping", philo);
		ft_sleep(all->time_sleep, all->num_philo);
		ft_display(philo->id, "is thinking", philo);
	}
	pthread_join(philo->loop_thread, NULL);
	if (ft_flag_die(philo, READ))
		exit(1);
	ft_free_semaphore(all);
	pthread_mutex_destroy(&(philo->m_die));
	exit(0);
	//exit(ret);

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
			return ;
		}
	}
	ft_free_semaphore(all);
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
	//	usleep(1000);
	}
	ft_waitpid_philo(all);
	return (1);
}

void	ft_semaphore(t_info *all)
{
	if (!(ft_create_process(all)))
		printf("Error fork\n");
}
