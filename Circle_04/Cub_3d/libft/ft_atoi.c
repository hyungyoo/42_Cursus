#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long int	final_nbr;
	int					sign;
	int					i;

	i = 0;
	sign = 1;
	final_nbr = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = sign * -1;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		final_nbr = final_nbr * 10 + (str[i] - '0');
		i++;
	}
	return (final_nbr * sign);
}
