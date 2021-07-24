#include "../cub3d.h"

int	player_check(char c, char *player)
{
	int	i;

	i = 0;
	while (player[i])
	{
		if (c == player[i])
			return (1);
		i++;
	}
	return (0);
}

void	create_player(t_game *game, int i, int j)
{
	if (game->player.dir)
		error_msg("ERROR: More than one player exist");
	game->player.dir = game->map.map[i][j];
	game->player.dir_x = -1.0;
	game->player.dir_y = 0.0;
	game->player.plane_x = 0.0;
	game->player.plane_y = 0.66;
	game->player.move_speed = 0.07;
	game->player.rotation_speed = 0.05;
	game->player.x = 0.5 + j;
	game->player.y = 0.5 + i;
	put_player_position(game);
}

void	put_player_position(t_game *game)
{
	int	degree;

	degree = 0;
	if (game->player.dir == 'N')
		degree = 270;
	else if (game->player.dir == 'W')
		degree = 0;
	else if (game->player.dir == 'S')
		degree = 90;
	else if (game->player.dir == 'E')
		degree = 180;
	rotate_player(&game->player, degree_to_radian(degree));
}

void	rotate_player(t_player *player, double rotation_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rotation_speed) - player->dir_y
		* sin(rotation_speed);
	player->dir_y = old_dir_x * sin(rotation_speed) + player->dir_y
		* cos(rotation_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rotation_speed) - player->plane_y
		* sin(rotation_speed);
	player->plane_y = old_plane_x * sin(rotation_speed) + player->plane_y
		* cos(rotation_speed);
}
