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
	float	w;
	float	h;
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

int	ft_is_rec(float x, float y, t_circle *cir)
{
	if (x < cir->x || cir->x + cir->w < x || cir->y > y || cir->y + cir->h  < y)
		return (0);
	else if (x - cir->x < 1 || cir->x + cir->w - x < 1 || 1 > y - cir->y || cir->y + cir->h - y < 1)
		return (1);
	return (2);
}

int	main(int argc, char **argv)
{
	FILE *fd;
	fd = NULL;
	int	res;
	t_circle	cir;

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
					res = fscanf(fd, "\n%c %f %f %f %f %c", &cir.c, &cir.x, &cir.y, &cir.w, &cir.h, &cir.draw);
					if (res == -1)
						return (ft_error(fd, 0));
					else if (res != 6 || cir.w <= 0 || cir.h <= 0|| (cir.c != 'r' && cir.c != 'R'))
						break;
					for (int y = 0; y < H; y++)
					{
						for (int x = 0; x < W; x++)
						{
							if (ft_is_rec(x, y, &cir) == 1)// && cir.c ==  'r')
								TAB[y][x] = cir.draw;
							else if (ft_is_rec(x, y, &cir) == 2 && cir.c == 'R')
								TAB[y][x] = cir.draw;
						}
					}
				}

			}
		}
	}
	return (ft_error(fd, 1));
}


