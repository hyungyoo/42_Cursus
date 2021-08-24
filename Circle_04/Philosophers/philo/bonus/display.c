/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:30:37 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/24 12:40:02 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

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
	sem_wait(all->msg);
	if (!(all->flag_die))
		printf("%lld %d %s\n", ft_get_time() - all->time_start, id + 1, str);
	sem_post(all->msg);
}

int	ft_print_error(char *str)
{
	printf("%s\n", str);
	return (0);
}
