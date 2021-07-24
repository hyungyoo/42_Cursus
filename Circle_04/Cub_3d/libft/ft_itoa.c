#include "libft.h"

int	ft_int_len(int n)
{
	int	i;

	if (n < 0)
		i = 1;
	else
		i = 0;
	if (n < 0)
		n = n * -1;
	if (n == 0)
		i = 1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	ft_decide_mark(int n, int *mark)
{
	if (n < 0)
		*mark = 1;
	else
		*mark = 0;
}

char	*ft_malloc_str(char *str, int i)
{
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		mark;

	ft_decide_mark(n, &mark);
	i = ft_int_len(n);
	ft_malloc_str(str, i);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		n = n * -1;
	str[i] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[i - 1] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	if (mark == 1)
		str[0] = '-';
	return (str);
}
