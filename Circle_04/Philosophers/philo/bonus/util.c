#include "philo_bonus.h"

int	ft_atoi(const char *str)
{
	long int	n;
	int			sign;

	n = 0;
	sign = 1;
	while ((*str <= 13 && *str >= 9) || *str == 32)
		str++;
	if (*str == '-')
		return (-1);
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			n = n * 10 + (*str++ - '0');
		else
			return (-1);
	}
	return ((int)(n * sign));
}

long long	ft_timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long long	ft_time_diff(long long past, long long pres)
{
	return (pres - past);
}

void	ft_smart_sleep(long long time, t_info *all)
{
	long long	i;

	i = ft_timestamp();
	while (!(all->dieded))
	{
		if (ft_time_diff(i, ft_timestamp()) >= time)
			break ;
		usleep(50);
	}
}

void	ft_action_print(t_info *all, int id, char *string)
{
	sem_wait(all->writing);
	if (!(all->dieded))
	{
		printf("%lli ", ft_timestamp() - all->first_timestamp);
		printf("%i ", id + 1);
		printf("%s\n", string);
	}
	sem_post(all->writing);
	return ;
}
