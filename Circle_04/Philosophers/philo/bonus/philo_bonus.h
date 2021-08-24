#ifndef PHILO_H
# define PHILO_H

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

struct s_rules;

typedef	struct			s_philosopher
{
	int					id;
	int					x_ate;
	int					left_fork_id;
	int					right_fork_id;
	long long			t_last_meal;
	struct s_rules		*rules;
	pthread_t			death_check;
	pid_t				proc_id;
}						t_philosopher;

typedef struct			s_rules
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
	t_philosopher		philosophers[250];
}						t_rules;

/*
** ----- error_manager.c -----
*/

int						ft_write_error(char *str);
int						ft_error_manager(int error);

/*
** ----- init.c -----
*/

int						ft_init_all(t_rules *rules, char **argv);

/*
** ----- utils.c -----
*/

int						ft_atoi(const char *str);
void					ft_action_print(t_rules *rules, int id, char *string);
long long				ft_timestamp(void);
long long				ft_time_diff(long long past, long long pres);
void					ft_smart_sleep(long long time, t_rules *rules);

/*
** ----- launcher.c -----
*/

int						ft_launcher(t_rules *rules);
void					ft_exit_launcher(t_rules *rules);

#endif
