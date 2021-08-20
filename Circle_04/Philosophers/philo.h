/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:43:32 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/20 17:00:27 by hyungyoo         ###   ########.fr       */
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

struct	s_info;

typedef struct	s_philo
{
	int				id;
	int				count_eat;
	int				r_fork;
	int				l_fork;
	long long		last_eat;
	struct s_info	*info;
}				t_philo;

typedef struct	s_info
{
	int					limit_eat;
	int					num_philo;
	int					time_death;
	int					time_eat;
	int					time_sleep;
	int					flag_all_ate;
	int					flag_die;
	long long			time_start;
	t_philo				*philo;
	pthread_mutex_t		*fork;
	pthread_mutex_t		*msg;
}				t_info;

/*
 * init.c
 */
void	ft_init(int argc, char **argv, t_info *all);

/*
 * display.c
 */
void	ft_print_error(char *str);

/*
 * util.c
 */
int		ft_atoi(char *nbr);

#endif
