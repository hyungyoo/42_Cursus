#include "libft.h"

int	ft_only_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
