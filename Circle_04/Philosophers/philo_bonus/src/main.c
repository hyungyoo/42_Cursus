/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:37:26 by hyungyoo          #+#    #+#             */
/*   Updated: 2022/07/06 21:37:45 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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
