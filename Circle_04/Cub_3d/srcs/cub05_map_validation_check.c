#include "../cub3d.h"

void	map_validation_check(t_game *game)
{
	if (game->player.dir == '\0')
		error_msg("ERROR: Player position missing");
	if (game->map.width_count == 0 || game->map.height_count == 0)
		error_msg("ERROR: Map has no validate width or height");
	horizontal_lines_map_check(game);
	vertical_lines_map_check(game);
}

void	horizontal_lines_map_check(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height_count)
	{
		if (game->map.map[y][0] == '0')
			error_msg("ERROR: Missing wall on the left side of the map");
		x = 1;
		while (x < game->map.width_count)
		{
			while (x < game->map.width_count && game->map.map[y][x] == ' ')
				x++;
			if (x == game->map.width_count)
				break ;
			if (game->map.map[y][x - 1] == ' ' && game->map.map[y][x] != '1')
				error_msg("ERROR: Missing wall on the left side of the map");
			while (x < game->map.width_count && game->map.map[y][x] != ' ')
				x++;
			if (game->map.map[y][x - 1] != '1')
				error_msg("ERROR: Missing wall on the right side of the map");
		}
		y++;
	}
}

void	vertical_lines_map_check(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map.width_count)
	{
		if (game->map.map[0][x] == '0')
			error_msg("ERROR: Missing wall on the upper side of the map");
		y = 1;
		while (y < game->map.height_count)
		{
			while (y < game->map.height_count && game->map.map[y][x] == ' ')
				y++;
			if (y == game->map.height_count)
				break ;
			if (game->map.map[y - 1][x] == ' ' && game->map.map[y][x] != '1')
				error_msg("ERROR: Missing wall on the upper side of the map");
			while (y < game->map.height_count && game->map.map[y][x] != ' ')
				y++;
			if (game->map.map[y - 1][x] != '1')
				error_msg("ERROR: Missing wall on the bottom side of the map");
		}
		x++;
	}
}
