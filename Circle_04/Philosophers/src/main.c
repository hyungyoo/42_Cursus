/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:42:05 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/20 23:35:13 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	t_info	all;

	ft_init(argc, argv, &all);
	ft_thread(&all);
	free(all.fork);
	free(all.philo);
	return (0);
}