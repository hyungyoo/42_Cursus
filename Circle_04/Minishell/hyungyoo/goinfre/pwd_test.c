#include "../includes/minishell.h"

int	main(void)
{
	char *str;

	str = getenv("PWD");
	printf("%s\n", str);
	return (0);
}
