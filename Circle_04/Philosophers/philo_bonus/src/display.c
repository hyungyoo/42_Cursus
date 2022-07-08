/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:45:52 by hyungyoo          #+#    #+#             */
/*   Updated: 2022/07/08 04:08:40 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_display(int id, char *str, t_philo *philo)
{
	sem_wait(philo->all->msg);
	if (!(ft_flag_die(philo, READ)))
		printf("%lld %d %s\n", ft_get_time() - philo->all->time_start, id + 1, str);
	sem_post(philo->all->msg);
}

int	ft_print_error(char *str)
{
	printf("%s\n", str);
	return (0);
}
