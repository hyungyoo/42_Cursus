#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t	mutex_lock;
int	g_count = 0;

void	*ft_t(void	*data)
{
	int	i;
	char	*thread_name = (char *)data;

	pthread_mutex_lock(&mutex_lock);
	
	// critical section
	g_count = 0; // 쓰레스마다 0부터 시작
	i = 0;
	while (i < 3)
	{
		i++;
		printf("%s COUNT %d\n", thread_name, g_count);
		g_count++;
		sleep(1);
	}
	pthread_mutex_unlock(&mutex_lock);
	return (NULL);
}

int	main(void)
{
	pthread_t	p_thread1;
	pthread_t	p_thread2;
	int			status;

	pthread_mutex_init(&mutex_lock, NULL);

	pthread_create(&p_thread1, NULL, ft_t, (void*)"Thread1");
	pthread_create(&p_thread2, NULL, ft_t, (void*)"Thread2");

	pthread_join(p_thread1, (void*)&status);
	pthread_join(p_thread2, (void*)&status);
	return (0);
}
