/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:43:32 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/20 02:29:31 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct	s_philo
{
	int		id;
	int		count_eat;
	int		r_fork;
	int		l_fork;
	struct s_info	*info;
}				t_philo;

typedef struct	s_info
{
	int				num_eat;
	t_philo	*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*msg;
}				t_info;

#endif
