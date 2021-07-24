#include "../cub3d.h"

void	ray_processing(t_game *game)
{
	int	x;

	x = 0;
	render_ceiling_and_floor(game);
	while (x < game->info.win_width)
	{
		init_ray(game, x);
		calculate_ray_pos_and_dir(game);
		set_dda(game);
		calculate_dist_to_wall(game);
		draw_ray_per_line(game);
		ray_wall_draw(game, x);
		game->z_buffer[x] = game->ray.perp_walldist;
		x++;
	}
}

void	init_ray(t_game *game, int x)
{
	game->ray.camera_x = 2 * x / (double)game->info.win_width - 1;
	game->ray.dir_x = game->player.dir_x + game->player.plane_x
		* game->ray.camera_x * -1;
	game->ray.dir_y = game->player.dir_y + game->player.plane_y
		* game->ray.camera_x * -1;
	game->ray.map_x = (int)(game->player.x);
	game->ray.map_y = (int)(game->player.y);
	game->ray.deltadist_x = fabs(1 / game->ray.dir_x);
	game->ray.deltadist_y = fabs(1 / game->ray.dir_y);
	game->ray.hit = 0;
}
