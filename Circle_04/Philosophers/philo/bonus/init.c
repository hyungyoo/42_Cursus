#include "philo_bonus.h"

int	ft_init_semaphore(t_info *all)
{
	sem_unlink("/philo_forks");
	sem_unlink("/philo_write");
	sem_unlink("/philo_mealcheck");
	all->forks = sem_open("/philo_forks", O_CREAT, S_IRWXU, all->nb_philo);
	all->writing = sem_open("/philo_write", O_CREAT, S_IRWXU, 1);
	all->meal_check = sem_open("/philo_mealcheck", O_CREAT, S_IRWXU, 1);
	return (0);
}

int	ft_init_philo(t_info *all)
{
	int	i;

	i = all->nb_philo;
	while (--i >= 0)
	{
		all->philo[i].id = i;
		all->philo[i].x_ate = 0;
		all->philo[i].t_last_meal = 0;
		all->philo[i].all = all;
	}
	return (0);
}

int	ft_init_all(t_info *all, char **argv)
{
	all->nb_philo = ft_atoi(argv[1]);
	all->time_death = ft_atoi(argv[2]);
	all->time_eat = ft_atoi(argv[3]);
	all->time_sleep = ft_atoi(argv[4]);
	all->dieded = 0;
	if (all->nb_philo < 1 || all->time_death < 0 || all->time_eat < 0
		|| all->time_sleep < 0 || all->nb_philo > 250)
		return (1);
	if (argv[5])
	{
		all->nb_eat = ft_atoi(argv[5]);
		if (all->nb_eat <= 0)
			return (1);
	}
	else
		all->nb_eat = -1;
	if (all->nb_eat == 1)
		all->nb_eat++;
	if (ft_init_semaphore(all))
		return (2);
	ft_init_philo(all);
	return (0);
}
