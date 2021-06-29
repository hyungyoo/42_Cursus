#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int		main(int argc, char **argv)
{
	int i = 0;
	int	check[256];

	while (i < 256)
		check[i++] = 0;
	if (argc == 3)
	{
		i = 0;
		while (i < ft_strlen(argv[1]))
		{
			if (check[(int)argv[1][i]] == 0)
			{
				check[(int)argv[1][i]] = 1;
				ft_putchar(argv[1][i]);
			}
			i++;
		}
		i = 0;
		while (i < ft_strlen(argv[2]))
		{
			if (check[(int)argv[2][i]] == 0)
			{
				check[(int)argv[2][i]] = 1;
				ft_putchar(argv[2][i]);
			}
			i++;
		}
	}
	// print \n
	ft_putchar('\n');
	return (0);
}
