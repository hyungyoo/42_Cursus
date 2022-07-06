/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hyungyoo <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/08/21 18:30:23 by hyungyoo		  #+#	#+#			 */
/*   Updated: 2022/07/06 20:52:51 by hyungyoo         ###   ########.fr       */
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

# define FIRST 1
# define SECOND 0
# define WRITE 1
# define READ 0

struct	s_info;

typedef struct s_philo
{
	int					id;
	int					count_eat;
	int					r_fork;
	int					l_fork;
	pthread_t			thread_id;
	long long			last_eat;
	pthread_mutex_t		m_count_eat;
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
	int					flag_die;
	long long			time_start;
	t_philo				*philo;
	pthread_mutex_t		*fork;
	pthread_mutex_t		msg;
	pthread_mutex_t		checker;
	pthread_mutex_t		die;
	pthread_mutex_t		eat;
	pthread_mutex_t		m_flag_eat;
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

/*
* mutex_lock.c
*/
int			ft_flag_die(t_info *all, int flag);
int			ft_flag_eat(t_info *all, int flag);
int			ft_count_eat(t_philo *philo, int flag);
void		ft_mutex_eat(t_philo *philo);
#endif
