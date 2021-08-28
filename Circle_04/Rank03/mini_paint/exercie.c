#include <string.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int	W;
int	H;
char	BG;
char	**TAB;

typedef struct s_circle
{
	char	t;
	float	x;
	float	y;
	float	r;
	char	c;
}				t_circle;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
	ft_putchar('\n');
}

int	ft_error(FILE *fd, int err)
{
	if (err == 2 && (err = 1))
		ft_putstr("Error: Operation file");
	else if (err == 1)
		ft_putstr("Error: argument");
	else
	{//////////////////////afficher///////////////////////////////
		int	i = 0;
		int	j;

		while (i < H)
		{
			j = 0;
			while (j < W)
			{
				write(1, &TAB[i][j], 1);
				j++;
			}
			i++;
			write(1, "\n", 1);
		}
	}
	if (fd)
		fclose(fd);
	return (err);
}

int	main(int argc, char **argv)
{
	t_circle	cir;
	FILE		*fd;
	int			res;
	// float!! int			sqr;
	float		sqr;

	fd = NULL;
	if (argc != 2)
		return (ft_error(fd, 1));
	if (!(fd = fopen(argv[1], "r")))
		return (ft_error(fd, 2));
	else
	{
		if ((res = fscanf(fd, "%d %d %c", &W, &H, &BG)) == 3)
		{
			if (W > 0 && W <= 300 && H > 0 && H <= 300)
			{
				TAB = malloc(sizeof(char *) * H);
				for (int i = 0;i < H;i++)
				{
					TAB[i] = malloc(sizeof(char) * W);
					memset(TAB[i], BG, W);
				}
				while (42)
				{
					res = fscanf(fd, "\n%c %f %f %f %c", &cir.t, &cir.x, &cir.y, &cir.r, &cir.c);
					if (res == -1)
						return (ft_error(fd, 0));
					else if (res != 5 || cir.r <= 0 || (cir.t != 'c' && cir.t != 'C'))
						break ;
					int	row = 0;
					int	col;
	
					while (row < H)
					{
						// col == 0
						col = 0;
						while (col < W)
						{
							sqr = sqrtf((cir.x - col) * (cir.x - col) + (cir.y - row)  * (cir.y - row));
							if (sqr <= cir.r)
							{
								if (cir.t == 'c' && sqr + 1 > cir.r)
									TAB[row][col] = cir.c;
								else if (cir.t == 'C')
									TAB[row][col] = cir.c;
							}
							col++;
						}
						row++;
					}
				}
			}
		}
	}
	return (ft_error(fd, 0));
}

		
