#include "philo_bonus.h"

int	ft_write_error(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	write(2, "Error: ", 7);
	write(2, str, len);
	write(2, "\n", 1);
	return (1);
}

int	ft_error_manager(int error)
{
	if (error == 1)
		return (ft_write_error("At least one wrong argument"));
	if (error == 2)
		return (ft_write_error("Fatal error when intializing semaphores"));
	return (1);
}
