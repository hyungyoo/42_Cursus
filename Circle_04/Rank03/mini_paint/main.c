#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

int		W;
int		H;
char	BG;
char	**TAB;

void	ft_putchar(char	c)
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

typedef struct	s_draw
{
	char	t;
	float	x;
	float	y;
	float	r;
	char	c;
}				t_draw;

int	ft_error(FILE *fd, int err)
{
	if (err == 2 &&  (err = 1))
		ft_putstr("Error: Operation file corrupted");
	else if (err == 1)
		ft_putstr("Error: argument");
	else
	{
		for (int i = 0; i < H; i++)
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
	t_draw		cir;
	FILE		*fd;
	float		sqr;
	int			res;

	fd = NULL;
	if (argc != 2)
		return (ft_error(fd, 1));
	if ((fd = fopen(argv[1], "r")))
	{
		if ((res = fscanf(fd, "%d %d %c", &W, &H, &BG)) == 3)
		{
			if (W > 0 && W <= 300 && H > 0 && H <= 300)
			{
				if (!(TAB = malloc(sizeof(char *) * H)))
					return (0);
				for (int i = 0; i < H; i++)
				{
					if (!(TAB[i] = (char*)malloc(sizeof(char) * W)))
						return (0);
					memset(TAB[i], BG, W);
				}
				while (42)
				{
					res = fscanf(fd, "\n%c %f %f %f %c", &cir.t, &cir.x, &cir.y, &cir.r, &cir.c);
					if (res == -1)
						return (ft_error(fd, 0));
					else if (res != 5 || cir.r <=  0 || (cir.t != 'c' && cir.t != 'C'))
						break ;
					for (int row = 0; row < H; row++)
					{
						for (int col = 0; col < W; col++)
						{
							sqr = sqrtf((col - cir.x) * (col - cir.x) + (row - cir.y) * (row - cir.y));
							if (sqr <= cir.r)
							{
								if (cir.t == 'c' && sqr + 1 > cir.r)
									TAB[row][col] = cir.c;
								else if (cir.t == 'C')
									TAB[row][col] = cir.c;
							}
						}
					}
				}
			}
		}
	}
	return (ft_error(fd, 2));
}
