/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:43:32 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/20 23:42:38 by hyungyoo         ###   ########.fr       */
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

typedef struct s_philo
{
	int				id;
	int				count_eat;
	int				r_fork;
	int				l_fork;
	pthread_t		thread_id;
	long long		last_eat;
	struct s_info	*all;
}				t_philo;

typedef struct s_info
{
	int					limit_eat;
	int					num_philo;
	int					time_death;
	int					time_eat;
	int					time_sleep;
	int					flag_eat;
	int					flag_die;
	long long			time_start;
	t_philo				*philo;
	pthread_mutex_t		*fork;
	pthread_mutex_t		msg;
	pthread_mutex_t		checker;
}				t_info;

/*
 * thread.c
 */
void		ft_thread(t_info *all);
void		ft_eat(t_philo *philo);
void		ft_sleep_think(t_philo *philo);
void		*ft_philo(void	*philo_ptr);
/*
 * init.c
 */
void		ft_init(int argc, char **argv, t_info *all);
int			ft_digit(char c);
void		ft_arg(int argc, char **argv);
/*
 * display.c
 */
void		ft_print_error(char *str);
void		ft_display(int id, char *str, t_info *all);
/*
 * util.c
 */
int			ft_atoi(char *nbr);

/*
 * sleep.c
 */
long long	ft_get_time(void);
void		ft_sleep(long long time);
#endif
