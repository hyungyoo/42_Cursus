#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t	mutex_lock;

int	g_count = 0;

void	*ft_u(void	*data)
{
	char	*thread_name = (char *)data;
	int	i = 0;

		// critical section
	while (i++ < 10000)
	{

		// entry section
		pthread_mutex_lock(&mutex_lock);

		g_count++;
		printf(" COUNT %d\n", g_count);
		// exit section
		pthread_mutex_unlock(&mutex_lock);
	}
		// remainder section
	pthread_exit(0);
}

void	*ft_d(void	*data)
{
	char	*thread_name = (char *)data;
	int	i = 0;
		// critical section
	while (i++ < 10000)
	{
		// entry section
		pthread_mutex_lock(&mutex_lock);
		
		g_count--;
		printf("COUNT %d\n", g_count);
		// exit section
		pthread_mutex_unlock(&mutex_lock);
	}	
		// remainder section
	pthread_exit(0);
}

int	main(void)
{
	pthread_t	p_thread1;
	pthread_t	p_thread2;
	int			status;

	pthread_mutex_init(&mutex_lock, NULL);

	pthread_create(&p_thread1, NULL, ft_u, NULL);
	pthread_create(&p_thread2, NULL, ft_d, NULL);

	pthread_join(p_thread1, NULL);
	pthread_join(p_thread2, NULL);
	pthread_mutex_destroy(&mutex_lock);

	printf("==========resultat : %d\n", g_count);
	return (0);
}
