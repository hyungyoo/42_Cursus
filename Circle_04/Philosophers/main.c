/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:42:05 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/19 18:07:45 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	ft_get_time(void)
{
	struct timeval	now;
	long int		now_int;

	gettimeofday(&now, NULL);
	now_int = (now.tv_sec * 1000) + (now.tv_usec / 1000);
	return (now_int);
}

void	ft_putnbr(long int n)
{
	char c;

	if (n > 9)
	{
		ft_putnbr(n / 10);
		c = n % 10 + '0';
		write(1, &c, 1);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_sleep(int time_sleep)
{
	long int	time;

	time = ft_get_time();
	while ((ft_get_time() - time) < time_sleep)
		usleep(time_sleep / 10);
}

int main(void)
{
		
		printf("1\n");
		ft_putnbr(ft_get_time());
		ft_putstr("\n");
		ft_sleep(200);;
		ft_putnbr(ft_get_time());
		ft_putstr("\n");
		printf("2\n");
		long int b = ft_get_time();
		usleep(200);

		ft_putnbr(ft_get_time() - b);
	
		ft_putstr("\n");
		printf("3\n");
		long int c = ft_get_time();
		ft_sleep(200);

		ft_putnbr(ft_get_time() - c);
		return 0;
}
