/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:30:23 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/24 13:37:26 by hyungyoo         ###   ########.fr       */
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
# include <sys/wait.h>
# include <semaphore.h>
# include <sys/stat.h>
# include <fcntl.h>

struct	s_info;

typedef struct s_philo
{
	int				id;
	int				count_eat;
	pthread_t		thread_id;
	pid_t			pid_philo;
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
	sem_t				*fork;
	sem_t				*msg;
	sem_t				*checker;
}				t_info;

/*
 * thread.c
 */
void		ft_thread(t_info *all);
void		ft_eat(t_philo *philo);
void		ft_sleep_think(t_philo *philo);
void		*ft_philo(t_philo *philo_ptr);
void		*ft_loop_checker(void *philo_ptr);
/*
 * init.c
 */
int			ft_init(int argc, char **argv, t_info *all);
int			ft_digit(char c);
int			ft_arg(int argc, char **argv);
int			ft_init_all1(int argc, char **argv, t_info *all);
int			ft_init_all2(char **argv, t_info *all);

/*
 * display.c
 */
int			ft_print_error(char *str);
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
