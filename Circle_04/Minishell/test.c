#include <stdio.h>
#include <readline/readline.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>

void	handle(int sig)
{
		if (sig == SIGINT)
		{
			printf("sigint\n");
		}
		else if (sig == SIGQUIT)
		{
			printf("\b\b	\b\b");
		}
}

int	main(void)
{
	signal(SIGINT, handle);
	return (0);
}
