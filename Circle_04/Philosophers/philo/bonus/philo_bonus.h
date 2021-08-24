#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <sys/time.h>
# include <sys/wait.h>
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>

struct	s_info;

typedef struct s_philo
{
	int					id;
	int					x_ate;
	int					left_fork_id;
	int					right_fork_id;
	long long			t_last_meal;
	struct s_info		*all;
	pthread_t			death_check;
	pid_t				proc_id;
}						t_philo;

typedef struct s_info
{
	int					nb_philo;
	int					time_death;
	int					time_eat;
	int					time_sleep;
	int					nb_eat;
	int					dieded;
	long long			first_timestamp;
	sem_t				*meal_check;
	sem_t				*forks;
	sem_t				*writing;
	t_philo				philo[250];
}						t_info;

/*
** ----- display.c -----
*/
int						ft_write_error(char *str);
int						ft_error_manager(int error);

/*
** ----- init.c -----
*/

int						ft_init_all(t_info *all, char **argv);

/*
** ----- util.c -----
*/

int						ft_atoi(const char *str);
void					ft_action_print(t_info *all, int id, char *string);
long long				ft_timestamp(void);
void					ft_smart_sleep(long long time, t_info *all);

/*
** ----- process.c -----
*/

int						ft_process_loop(t_info *all);
void					ft_exit_launcher(t_info *all);

#endif
