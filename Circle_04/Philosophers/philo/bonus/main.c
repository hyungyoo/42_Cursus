/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:42:05 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/23 21:52:24 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	main(int argc, char **argv)
{
	t_info	all;

	if (!(ft_init(argc, argv, &all)))
		return (0);
	ft_thread(&all);
	if (all.fork)
		free(all.fork);
	if (all.philo)
		free(all.philo);
	return (0);
}
