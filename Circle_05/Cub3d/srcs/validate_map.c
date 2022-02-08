#include "cub3d.h"

/* 
 *  map -> width, height (info check)
 * */
void	validate_map(t_info	*all)
{
	check_map_element(all);
	if (!all->env.width || !all->env.height)
		ft_strexit("Error: Invalid info map! 🙉");
	if (all->player.dir == '\0')
		ft_strexit("Error: No player position has given! 🙉");
	horizontal_read_map(all->map, all->env.width, all->env.height);
	vertical_read_map(all->map, all->env.width, all->env.height);
}

/* 
 * Verify horizontal map - closed wall on the left/right/up/down
 * */
void	horizontal_read_map(char **map, int width, int height)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		if (map[y][0] != ' ' && map[y][0] != WALL)
			ft_strexit("Error: Map is not surrounded by leftside walls!🙊");
		x = 1;
		while (x < width)
		{
			while (x < width && map[y][x] == ' ')
				x++;
			if (x == width)
				break ;
			if (map[y][x - 1] == ' ' && map[y][x] != WALL)
				ft_strexit("Error: Map is not surrounded by leftside walls!🙊");
			while (x < width && map[y][x] != ' ')
				x++;
			if (map[y][x - 1] != WALL)
				ft_strexit("Error: Map is not surrounded by rightside walls!🙊");
		}
		y++;
	}
}

/*
 * Verify Vertical map - closed wall on the upperside bottomside wall
 * */
void	vertical_read_map(char **map, int width, int height)
{
	int	x;
	int	y;

	x = 0;
	while (x < width)
	{
		if (map[0][x] != ' ' && map[0][x] != WALL)
			ft_strexit("Error: Map is not surrounded by upperside walls!🙊");
		y = 1;
		while (y < height)
		{
			while (y < height && map[y][x] == ' ')
				y++;
			if (y == height)
				break ;
			if (map[y -1][x] == ' ' && map[y][x] != WALL)
				ft_strexit("Error: Map is not surrounded by upperside walls!🙊");
			while (y < height && map[y][x] != ' ')
				y++;
			if (map[y -1][x] != WALL)
				ft_strexit
					("Error: Map is not surrounded by bottomside walls!🙊");
		}
		x++;
	}
}
