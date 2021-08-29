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
	float	width;
	float	height;
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

int	ft_is_rec(float x, float y, t_draw *rec)
{
	
	if ((((x < rec->x) || (rec->x + rec->width < x)) || ((y < rec->y) || (rec->y + rec->height < y))))
		return (0);
	if ((((x - rec->x < 1.00000000) || (rec->x + rec->width - x < 1.00000000)) || (((y - rec->y < 1.00000000) || (rec->y + rec->height - y < 1.00000000)))))
		return (2);	//border
	return (1);
}

int	main(int argc, char **argv)
{
	t_draw		rec;
	FILE		*fd;
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
					res = fscanf(fd, "\n%c %f %f %f %f %c", &rec.t, &rec.x, &rec.y, &rec.width, &rec.height, &rec.c);
					if (res == -1)
						return (ft_error(fd, 0));
					else if (res != 6 || rec.width <= 0.00000000 || rec.height <=  0.00000000 || (rec.t != 'r' && rec.t != 'R'))
						break ;
					for (int row = 0; row < H; row++)
					{
						for (int col = 0; col < W; col++)
						{
							if (ft_is_rec(col, row, &rec) == 2) // && rec.t == 'r'  ////////xxxxxxxxxx///////////
								TAB[row][col] = rec.c;
							else if (ft_is_rec(col, row, &rec) == 1 && rec.t == 'R') ///////////////////col, row/////////
								TAB[row][col] = rec.c;
						}
					}
				}
			}
		}
	}
	return (ft_error(fd, 2));
}
