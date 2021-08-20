/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 15:04:04 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/20 19:24:51 by hyungyoo         ###   ########.fr       */
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

void	ft_display(int id, char *str, t_info *all)
{
	pthread_mutex_lock(&(all->msg));
	if (!(all->flag_die))
		printf("%lld %d %s\n", ft_get_time() - all->time_start, id + 1, str);
	pthread_mutex_unlock(&(all->msg));
}

void	ft_print_error(char *str)
{
	printf("%s\n", str);
	exit(1);
}
