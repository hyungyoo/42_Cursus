#include <pthread.h>
#include <stdio.h>

int	sum = 0;

pthread_mutex_t	mutex;

void	*counter(void	*param)
{
	int	i= -1;

		// critical section
	while (i++ < 10000)
	{

		// entry section
		pthread_mutex_lock(&mutex);

		sum++;
		
		//printf("%s COUNT %d\n", thread_name, g_count);
		//usleep(1000);
		// exit section
		pthread_mutex_unlock(&mutex);
	}
		// remainder section
	pthread_exit(0);
	//return (NULL);
}


int	main(void)
{
	pthread_t	tid1;
	pthread_t	tid2;

	pthread_mutex_init(&mutex, NULL);

	pthread_create(&tid1, NULL, counter, NULL);
	pthread_create(&tid2, NULL, counter, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	printf("==========resultat : %d\n", sum);
	return (0);
}
