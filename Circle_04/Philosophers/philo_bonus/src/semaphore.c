/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:46:33 by hyungyoo          #+#    #+#             */
/*   Updated: 2022/07/08 07:00:12 by hyungyoo         ###   ########.fr       */
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
	//ft_display(philo->id, "is eating", philo);
	sem_post(all->checker);
	ft_display(philo->id, "is eating", philo);
	ft_sleep(all->time_eat, all->num_philo);
	ft_flag_eat_count(philo, WRITE);
	sem_post(all->fork);
	sem_post(all->fork);
}

void	ft_free_semaphore(t_info *all)
{
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
	//ft_flag_die(philo, WRITE);
	sem_post(all->checker);
	ft_free_semaphore(all);
	pthread_join(philo->loop_thread, NULL);
	//free(all->philo);
	exit(1);
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
			//ft_display(philo->id, "died", philo);
			//exit(1);
			ft_close_checker(philo);
		}
		sem_post(all->checker);
		//if (ft_flag_die(philo, READ))
		//	break ;
		usleep(1000);
		if (all->limit_eat != -1 && ft_flag_eat_count(philo, READ) >= all->limit_eat)
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
	while (!(ft_flag_die(philo, READ)) && !(all->limit_eat != -1 && ft_flag_eat_count(philo, READ) >= all->limit_eat))
	{
		ft_eat(philo);
		//if (ft_flag_die(philo, READ))
		//	break ;
		ft_display(philo->id, "is sleeping", philo);
		ft_sleep(all->time_sleep, all->num_philo);
		ft_display(philo->id, "is thinking", philo);
	}
	pthread_join(philo->loop_thread, NULL);
	if (ft_flag_die(philo, READ))
		ft_close_checker(philo);
	//ft_free_all(philo);
	ft_free_semaphore(philo->all);
	free(all->philo);	// here
	exit(0) ;
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
	//	usleep(1000);
	}
	//ft_waitpid_philo(all);
	return (1);
}

void	ft_semaphore(t_info *all)
{
	if (!(ft_create_process(all)))
		printf("Error fork\n");
	ft_waitpid_philo(all);
}
