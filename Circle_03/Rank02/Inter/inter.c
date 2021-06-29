#include <unistd.h>

int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int	check[256];
	int	i = 0;

	while (i < 256)
		check[i++] = 0;
	if (argc == 3)
	{
		i = 0;
		while (i < ft_strlen(argv[2]))
		{
			if (check[(int)argv[2][i]] == 0)
			{
				check[(int)argv[2][i]] = 1;
			}
			i++;
		}
		i = 0;
		while (i < ft_strlen(argv[1]))
		{
			if (check[(int)argv[1][i]] == 1)
			{
				check[(int)argv[1][i]] = 2;
				ft_putchar(argv[1][i]);
			}
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
