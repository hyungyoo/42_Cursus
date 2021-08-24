#ifndef PAINT_H
# define PAINT_H

#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		W;
int		H;
char	BG;
char	**TAB;

typedef struct	draw
{
	char	t;
	float	x;
	float	y;
	float	r;
	char	c;
}	Draw;

#endif
