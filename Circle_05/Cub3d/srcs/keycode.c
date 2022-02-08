#include "cub3d.h"

int	exit_key(t_info	*all)
{
	(void)all;
	ft_strexit("Key ESC : Exit successfully!✅");
	return (0);
}

int	execute_keypress(int key, t_info *all)
{
	if (key == KEY_W || key == KEY_UP)
		go_back_forward(all, &all->player, all->player.move_speed);
	if (key == KEY_S || key == KEY_DOWN)
		go_back_forward(all, &all->player, -all->player.move_speed);
	if (key == KEY_A)
		go_left_right(all, &all->player, all->player.move_speed);
	if (key == KEY_D)
		go_left_right(all, &all->player, -all->player.move_speed);
	if (key == KEY_LEFT)
		rotate_player(&all->player, -all->player.rot_speed);
	if (key == KEY_RIGHT)
		rotate_player(&all->player, all->player.rot_speed);
	if (key == KEY_ESC || key == X_EVENT_KEY_EXIT)
		ft_strexit("Key ESC : Exit successfully!✅");
	return (0);
}

void	go_back_forward(t_info *all, t_player *player, double move_speed)
{
	char	x;
	char	y;

	x = all->map[(int)player->y][(int)(player->x \
			+ player->dir_x * move_speed)];
	y = all->map[(int)(player->y + player->dir_y \
			*move_speed)][(int)player->x];
	if (x != WALL)
		player->x += player->dir_x * move_speed;
	if (y != WALL)
		player->y += player->dir_y * move_speed;
}

void	go_left_right(t_info *all, t_player *player, double move_speed)
{
	char	x;
	char	y;

	x = all->map[(int)player->y][(int)(player->x + \
			player->dir_x * move_speed)];
	y = all->map[(int)(player->y + player->dir_y * \
			move_speed)][(int)player->x];
	if (x != WALL)
		player->x += player->dir_y * move_speed;
	if (y != WALL)
		player->y += -player->dir_x * move_speed;
}
