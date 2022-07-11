/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hyungyoo <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/08/21 18:30:23 by hyungyoo		  #+#	#+#			 */
/*   Updated: 2022/07/11 19:55:31 by hyungyoo         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

# define FIRST 1
# define SECOND 0
# define WRITE 1
# define READ 0

struct	s_info;

typedef struct s_philo
{
	int					id;
	int					count_eat;
	long long			last_eat;
	pthread_mutex_t		m_die;
	pthread_mutex_t		m_eat;
	pthread_t			loop_thread;
	pid_t				philo_pid;
	int					flag_die;
	struct s_info		*all;
}	t_philo;

typedef struct s_info
{
	int					limit_eat;
	int					num_philo;
	int					time_death;
	int					time_eat;
	int					time_sleep;
	int					flag_eat;
	long long			time_start;
	t_philo				philo[250];
	sem_t				*fork;
	sem_t				*msg;
	sem_t				*checker;
}				t_info;

/*
* semaphore.c
*/
int				ft_flag_die(t_philo *philo, int flag);
int				ft_flag_eat_count(t_philo *philo, int flag);
void			ft_eat(t_philo *philo);
void			ft_free_semaphore(t_info *all);
void			ft_close_checker(t_philo *philo);
void			*ft_loop_checker(void *phi);
void			ft_monitor_philo(t_philo *philo);
void			ft_waitpid_philo(t_info *all);
int				ft_create_process(t_info *all);
void			ft_semaphore(t_info *all);

/*
* display.c
*/
void			ft_display(int id, char *str, t_philo *philo);
int				ft_print_error(char *str);

/*
* init.c init2.c
*/
void			ft_init_info(t_info *all);
int				ft_init_philo(t_info *all);
int				ft_init_semaphore(t_info *all);
int				ft_init(int argc, char **argv, t_info *all);
int				ft_init_all1(int argc, char **argv, t_info *all);
int				ft_init_all2(char **argv, t_info *all);
int				ft_arg(int argc, char **argv);

/*
* util.c
*/
int				ft_atoi(char *nbr);

/*
* sleep.c
*/
long long		ft_get_time(void);
void			ft_sleep(long long time, int num_philo);
#endif
