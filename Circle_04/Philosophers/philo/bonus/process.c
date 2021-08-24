#include "philo_bonus.h"

void	ft_philo_eats(t_philosopher *philo)
{
	t_info	*all;

	all = philo->all;
	sem_wait(all->forks);
	ft_action_print(all, philo->id, "has taken a fork");
	sem_wait(all->forks);
	ft_action_print(all, philo->id, "has taken a fork");
	sem_wait(all->meal_check);
	ft_action_print(all, philo->id, "is eating");
	philo->t_last_meal = ft_timestamp();
	sem_post(all->meal_check);
	ft_smart_sleep(all->time_eat, all);
	(philo->x_ate)++;
	sem_post(all->forks);
	sem_post(all->forks);
}

void	*ft_death_checker(void *void_philosopher)
{
	t_philosopher	*philo;
	t_info			*r;

	philo = (t_philosopher *)void_philosopher;
	r = philo->all;
	while (42)
	{
		sem_wait(r->meal_check);
		if (ft_time_diff(philo->t_last_meal, ft_timestamp()) > r->time_death)
		{
			ft_action_print(r, philo->id, "died");
			r->dieded = 1;
			sem_wait(r->writing);
			exit(1);
		}
		sem_post(r->meal_check);
		if (r->dieded)
			break ;
		usleep(1000);
		if (philo->x_ate >= r->nb_eat && r->nb_eat != -1)
			break ;
	}
	return (NULL);
}

void	ft_process(void *void_phil)
{
	t_philosopher	*philo;
	t_info			*all;

	philo = (t_philosopher *)void_phil;
	all = philo->all;
	philo->t_last_meal = ft_timestamp();
	pthread_create(&(philo->death_check), NULL, ft_death_checker, void_phil);
	if (philo->id % 2)
		usleep(15000);
	while (!(all->dieded))
	{
		ft_philo_eats(philo);
		if (philo->x_ate >= all->nb_eat && all->nb_eat != -1)
			break ;
		ft_action_print(all, philo->id, "is sleeping");
		ft_smart_sleep(all->time_sleep, all);
		ft_action_print(all, philo->id, "is thinking");
	}
	pthread_join(philo->death_check, NULL);
	if (all->dieded)
		exit(1);
	exit(0);
}

void	ft_exit_launcher(t_info *all)
{
	int	i;
	int	ret;

	i = 0;
	while (i < all->nb_philo)
	{
		waitpid(-1, &ret, 0);
		if (ret != 0)
		{
			i = -1;
			while (++i < all->nb_philo)
				kill(all->philosophers[i].proc_id, 15);
			break ;
		}
		i++;
	}
	sem_close(all->forks);
	sem_close(all->writing);
	sem_close(all->meal_check);
	sem_unlink("/philo_forks");
	sem_unlink("/philo_write");
	sem_unlink("/philo_mealcheck");
}

int	ft_process_loop(t_info *all)
{
	int				i;
	t_philosopher	*phi;

	i = -1;
	phi = all->philosophers;
	all->first_timestamp = ft_timestamp();
	while (++i < all->nb_philo)
	{
		phi[i].proc_id = fork();
		if (phi[i].proc_id < 0)
			return (1);
		if (phi[i].proc_id == 0)
			ft_process(&(phi[i]));
		usleep(100);
	}
	ft_exit_launcher(all);
	return (0);
}
