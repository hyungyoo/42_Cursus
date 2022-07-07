/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:46:21 by hyungyoo          #+#    #+#             */
/*   Updated: 2022/07/07 21:59:51 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	ft_get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

void	ft_sleep(long long time, int num_philo)
{
	long long	time_cmp;

	time_cmp = ft_get_time();
	while ((ft_get_time() - time_cmp) < time)
	{
		if (num_philo < 50)
			usleep(time / 10);
		else
			usleep(1000);
	}
}
