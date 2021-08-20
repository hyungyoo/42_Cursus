/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 10:43:26 by afoulqui          #+#    #+#             */
/*   Updated: 2021/08/04 14:24:11 by afoulqui         ###   ########.fr       */
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

typedef int		t_bool;
# define TRUE 1
# define FALSE 0

# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DEAD 5
# define END 6

# define N_PHI 0
# define T_DIE 1
# define T_EAT 2
# define T_SLEEP 3
# define LIMIT_MEAL 4

typedef struct s_table
{
	int				data[5];
	int				meals;
	long int		saved_time;
	t_bool			stop;
	pthread_mutex_t	*forks;
	pthread_mutex_t	msg;
	pthread_mutex_t	checker;
	pthread_mutex_t	death;
	struct s_philo	*philo;
}					t_table;

typedef struct s_philo
{
	int				id;
	int				nb_meals;
	long int		start_time;
	pthread_mutex_t	*r_frk;
	pthread_mutex_t	*l_frk;
	pthread_t		checker_thread;
	t_table			*table;
}					t_philo;

/*
**	MAIN
*/

int					parse(int argc, char **argv, t_table *table);
void				*routine(void *ptr);
void				*check_liveness(void *ptr);
void				display(t_philo *philo, int status);

/*
**	UTILS
*/

int					ft_isdigit(int c);
t_bool				ft_onlydigit(char **str);
int					ft_atoi(const char *str);
void				clear_all(t_table *table);
void				ft_putnbr(long int n);
int					ft_strlen(char *str);
void				ft_sleep(int time_sleep);
long int			get_time(void);

#endif