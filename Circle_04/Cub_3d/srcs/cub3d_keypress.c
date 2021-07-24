#include "../cub3d.h"

int	ft_keypress(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit_msg("CUB3D CLOSED, BYE!");
	if (key == KEY_W)
		move_forward(game, &game->player);
	if (key == KEY_S)
		move_backward(game, &game->player);
	if (key == KEY_A)
		move_right(game, &game->player);
	if (key == KEY_D)
		move_left(game, &game->player);
	if (key == KEY_LEFT)
		rotate_right(&game->player);
	if (key == KEY_RIGHT)
		rotate_left(&game->player);
	return (EXIT_SUCCESS);
}

void	rotate_right(t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	player->dir_x = player->dir_x * cos(-player->rotation_speed)
		- player->dir_y * sin(-player->rotation_speed);
	player->dir_y = old_dir_x * sin(-player->rotation_speed)
		+ player->dir_y * cos(-player->rotation_speed);
	player->plane_x = player->plane_x * cos(-player->rotation_speed)
		- player->plane_y * sin(-player->rotation_speed);
	player->plane_y = old_plane_x * sin(-player->rotation_speed)
		+ player->plane_y * cos(-player->rotation_speed);
}

void	rotate_left(t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	player->dir_x = player->dir_x * cos(player->rotation_speed)
		- player->dir_y * sin(player->rotation_speed);
	player->dir_y = old_dir_x * sin(player->rotation_speed)
		+ player->dir_y * cos(player->rotation_speed);
	player->plane_x = player->plane_x * cos(player->rotation_speed)
		- player->plane_y * sin(player->rotation_speed);
	player->plane_y = old_plane_x * sin(player->rotation_speed)
		+ player->plane_y * cos(player->rotation_speed);
}
