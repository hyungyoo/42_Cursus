#include "paint.h"

int	ft_strlen(char *str)
{
	int	ret = 0;
	while (str[ret])
		ret++;
	return (ret);
}

int	err_msg(FILE *fd, int err)
{
	if (err == 2 && err == 1)
		write(1, "Error: Operation file corrupted\n", ft_strlen("Error: Operation file corrupted\n"));
	else if (err == 1)
		write(1, "Error: argument\n", ft_strlen("Error: argument\n"));
	else
	{
		int	i;
		i = 0;
		while (i < H)
		{
			write(1, TAB[i], W);
			write(1, "\n", 1);
			i++;
		}
	}
	if (fd)
		fclose(fd);
	return (err);
}

int	main(int ac, char **av)
{
	Draw	el;
	FILE	*fd;
	float	sqr;
	int		res;

	fd = NULL;
	if (ac != 2)
		return (err_msg(fd, 1));
	if ((fd = fopen(av[1], "r")))
	{
		if ((res = fscanf(fd, "%d %d %c", &W, &H, &BG)) == 3)
		{
			if (W > 0 && W <= 300 && H > 0 && H <= 300)
			{
				TAB = malloc(H * sizeof(char *));
				int	i = 0;
				while (i < H)
				{
					TAB[i] = malloc(W * sizeof(char));
					memset(TAB[i], BG, W);
					i++;
				}
				while (1)
				{
					res = fscanf(fd, "\n%c %f %f %f %c", &el.t, &el.x, &el.y, &el.r, &el.c);
					if (res == -1)
						return (err_msg(fd, 0));
					else if (res != 5 || el.r <= 0 || (el.t != 'c' && el.t != 'C'))
						break ;
					int	line = 0;
					while (line < H)
					{
						int	col = 0;
						while (col < W)
						{
							sqr = sqrtf((col - el.x) * (col - el.x) + (line - el.y) * (line - el.y));
							if (sqr <= el.r)
							{
								if (el.t == 'c' && sqr + 1 > el.r)
									TAB[line][col] = el.c;
								else if (el.t == 'C')
									TAB[line][col] = el.c;
							}
							col++;
						}
						line++;
					}
				}
			}
		}
	}
	return (err_msg(fd, 2));
}
