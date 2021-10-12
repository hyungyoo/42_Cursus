#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		main(int argc, char **argv, char **env)
{
	int	sta;
	char *ret[3];
	ret[2] = NULL;
	ret[0] = "ls";
	ret[1] = "-al";
	pid_t a;
	a = fork();
	if (a == 0)
		execve("/bin/ls", ret, env);
	else if (a == 0)
	{
		waitpid(a, &sta, 0);
		printf("p\n");
	}
	printf("%s\n", getenv("PATH"));
	return (0);
}
