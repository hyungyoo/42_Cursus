#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

int		W;
int		H;
char	BG;
char	**TAB;

typedef struct s_circle
{
	char	c;
	float	x;
	float	y;
	float	r;
	char	draw;
}			t_circle;


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
	ft_putchar('\n');
}
	

int	ft_error(FILE *fd, int err)
{
	if (err == 2 && (err = 1))
		ft_putstr("Error: argument");
	else if (err == 1)
		ft_putstr("Error: Operation file corrupted");
	else
	{
		for (int i = 0; i < H;i++)
		{
			write(1, TAB[i], W);
			write(1, "\n", 1);
		}
	}
	if (fd)
		fclose(fd);
	return (err);
}

int	main(int argc, char **argv)
{
	FILE *fd;
	fd = NULL;
	int	res;
	t_circle	cir;
	float	distance;

	if (argc != 2)
		return (ft_error(fd, 2));
	if ((fd = fopen(argv[1], "r")))
	{
		if ((res = fscanf(fd, "%d %d %c", &W, &H, &BG)) == 3)
		{
			if (W > 0 && W <= 300 && H > 0 && H <= 300)
			{
				if (!(TAB = malloc(sizeof(char *) * H)))
					return (0);
				for (int i = 0;i < H; i++)
				{
					if (!(TAB[i] = malloc(sizeof(char) * W)))
						return (0);
					memset(TAB[i], BG, W);
				}
				while (42)
				{
					res = fscanf(fd, "\n%c %f %f %f %c", &cir.c, &cir.x, &cir.y, &cir.r, &cir.draw);
					if (res == -1)
						return (ft_error(fd, 0));
					else if (res != 5 || cir.r <= 0 || (cir.c != 'c' && cir.c != 'C'))
						break;
					for (int row = 0; row < H; row++)
					{
						for (int col = 0; col < W; col++)
						{
							distance = sqrtf((row - cir.y) * (row - cir.y) + (col - cir.x) * (col - cir.x));
							if (distance <= cir.r)
							{
								if ((distance + 1 > cir.r) && cir.c == 'c')
									TAB[row][col] = cir.draw;
								else if (cir.c == 'C')
									TAB[row][col] = cir.draw;
							}
						}
					}
				}

			}
		}
	}
	return (ft_error(fd, 1));
}


