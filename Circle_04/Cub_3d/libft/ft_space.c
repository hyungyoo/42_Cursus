#include "libft.h"

int	ft_space(int i)
{
	if (i == 32 || (i >= 9 && i <= 14))
		return (1);
	else
		return (0);
}
