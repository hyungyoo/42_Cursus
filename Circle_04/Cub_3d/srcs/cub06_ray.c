#include "../cub3d.h"

void	calculate_ray_pos_and_dir(t_game *game)
{
	if (game->ray.dir_x < 0)
	{
		game->ray.step_x = -1;
		game->ray.sidedist_x = (game->player.x - game->ray.map_x)
			* game->ray.deltadist_x;
	}
	else
	{
		game->ray.step_x = +1;
		game->ray.sidedist_x = (game->ray.map_x + 1.0 - game->player.x)
			* game->ray.deltadist_x;
	}
	if (game->ray.dir_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.sidedist_y = (game->player.y - game->ray.map_y)
			* game->ray.deltadist_y;
	}
	else
	{
		game->ray.step_y = +1;
		game->ray.sidedist_y = (game->ray.map_y + 1.0 - game->player.y)
			* game->ray.deltadist_y;
	}
}

void	set_dda(t_game *game)
{
	while (game->ray.hit == 0)
	{
		if (game->ray.sidedist_x < game->ray.sidedist_y)
		{
			game->ray.sidedist_x += game->ray.deltadist_x;
			game->ray.map_x += game->ray.step_x;
			if (game->ray.step_x == -1)
				game->ray.side = TEX_WEST;
			else
				game->ray.side = TEX_EAST;
		}
		else
		{
			game->ray.sidedist_y += game->ray.deltadist_y;
			game->ray.map_y += game->ray.step_y;
			if (game->ray.step_y == -1)
				game->ray.side = TEX_SOUTH;
			else
				game->ray.side = TEX_NORTH;
		}
		if (game->map.map[game->ray.map_y][game->ray.map_x] == '1')
			game->ray.hit = 1;
	}
}

void	calculate_dist_to_wall(t_game *game)
{
	if (game->ray.side == TEX_WEST || game->ray.side == TEX_EAST)
		game->ray.perp_walldist = (game->ray.map_x - game->player.x
				+ (1 - game->ray.step_x) / 2) / game->ray.dir_x;
	else
		game->ray.perp_walldist = (game->ray.map_y - game->player.y
				+ (1 - game->ray.step_y) / 2) / game->ray.dir_y;
}

void	draw_ray_per_line(t_game *game)
{
	game->ray.line_height = (int)(game->info.win_height
			/ game->ray.perp_walldist);
	game->ray.draw_start = (-game->ray.line_height / 2)
		+ (game->info.win_height / 2);
	if (game->ray.draw_start < 0)
		game->ray.draw_start = 0;
	game->ray.draw_end = (game->ray.line_height / 2)
		+ (game->info.win_height / 2);
	if (game->ray.draw_end >= game->info.win_height)
		game->ray.draw_end = game->info.win_height - 1;
	if (game->ray.side == TEX_WEST || game->ray.side == TEX_EAST)
		game->ray.wall_x = game->player.y + game->ray.perp_walldist
			* game->ray.dir_y;
	else
		game->ray.wall_x = game->player.x + game->ray.perp_walldist
			* game->ray.dir_x;
	game->ray.wall_x -= floor(game->ray.wall_x);
	game->ray.tex_x = (int)(game->ray.wall_x * (double)TEX_WIDTH);
	if (game->ray.side == TEX_EAST || game->ray.side == TEX_SOUTH)
		game->ray.tex_x = TEX_WIDTH - game->ray.tex_x - 1;
}

void	ray_wall_draw(t_game *game, int x)
{
	int	y;
	int	color;

	y = game->ray.draw_start;
	game->ray.step = 1.0 * TEX_HEIGHT / game->ray.line_height;
	game->ray.tex_pos = (game->ray.draw_start - game->info.win_height / 2
			+ game->ray.line_height / 2) * game->ray.step;
	while (y < game->ray.draw_end)
	{
		game->ray.tex_y = (int)game->ray.tex_pos & (TEX_HEIGHT - 1);
		game->ray.tex_pos += game->ray.step;
		color = game->info.texture[game->ray.side]
		[TEX_HEIGHT * game->ray.tex_y + game->ray.tex_x];
		if (game->ray.side == TEX_SOUTH || game->ray.side == TEX_NORTH)
			color = (color >> 1) & 8355711;
		game->buf[y][x] = color;
		y++;
	}
}
