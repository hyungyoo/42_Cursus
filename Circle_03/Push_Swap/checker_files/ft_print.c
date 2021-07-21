#include "../inc/checker.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_print_error(void)
{
	ft_putstr("Error\n");
	exit(0);
}
