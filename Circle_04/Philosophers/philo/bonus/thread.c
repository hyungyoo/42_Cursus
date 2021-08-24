/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:31:37 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/24 13:41:02 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_all_eat_checker(t_philo *philo)
{
	t_info	*all;

	all = philo->all;
	if (philo->count_eat == all->limit_eat)
		all->flag_eat = 1;
}

void	*ft_loop_checker(void *philo_ptr)
{
	int	i;
	t_philo	*philo;
	t_info	*all;

	philo = (t_philo *)philo_ptr;
	all = philo->all;
	philo->last_eat = ft_get_time();
	while (!(all->flag_eat))
	{
		i = -1;
		while (++i < all->num_philo && !(all->flag_die))
		{
			sem_wait(all->checker);
			if (ft_get_time() - philo->last_eat > all->time_death)
			{
				ft_display(philo->id, "died", all);
				all->flag_die = 1;
				sem_wait(all->msg);
				exit(1);
			}
			sem_post(all->checker);
		}
		if (all->flag_die == 1)
			break ;
		ft_all_eat_checker(philo);
	}
	return (NULL);
}

int	ft_create_process(t_info *all)
{
	int			i;
	int			j;
	int			status;
	pid_t		tmp;

	i = -1;
	all->time_start = ft_get_time();
	while (++i < all->num_philo)
	{
		all->philo[i].pid_philo = fork();
		tmp = all->philo[i].pid_philo;
		if (tmp > 0)
		{
			waitpid(-1, &status, 0);
			if (status != 0)
			{
				j = -1;
				while (++j < all->num_philo)
					kill(all->philo[j].pid_philo, 15);
			}
		}
		if (tmp == 0)
			ft_philo(&(all->philo[i]));
	}
	return (1);
}

void	ft_free_sem(t_info *all)
{
	sem_close(all->fork);
	sem_close(all->msg);
	sem_close(all->checker);
	sem_unlink("/philo_fork");
	sem_unlink("/philo_msg");
	sem_unlink("/philo_checker");
}

void	ft_thread(t_info *all)
{
	if (!(ft_create_process(all)))
		return ;
	ft_loop_checker(all);
	ft_free_sem(all);
}
