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

	int	i = 0;
	while (ret[i])
		i++;
	--i;
	printf("%s == -al\n",ret[i]);
	return (0);
}
