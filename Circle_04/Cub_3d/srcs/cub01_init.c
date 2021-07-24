#include "../cub3d.h"

void	all_init(t_game *game)
{
	int	i;

	i = 0;
	game->info.line = NULL;
	game->info.mark = 0;
	game->info.win_width = 0;
	game->info.win_height = 0;
	game->info.floor_color = -1;
	game->info.ceiling_color = -1;
	while (i < TEXTURE)
	{
		game->info.tex_path[i] = NULL;
		i++;
	}
	game->z_buffer = NULL;
	game->mlx = mlx_init();
	init_player(game);
	init_map(game);
}

void	init_map(t_game *game)
{
	game->map.tmp = NULL;
	game->map.buff = NULL;
	game->map.map = NULL;
	game->map.width_count = 0;
	game->map.height_count = 0;
}

void	init_player(t_game *game)
{
	game->player.dir = '\0';
	game->player.x = 0.0;
	game->player.y = 0.0;
	game->player.dir_x = 0.0;
	game->player.dir_y = 0.0;
	game->player.plane_x = 0.0;
	game->player.plane_y = 0.0;
	game->player.move_speed = 0.0;
	game->player.rotation_speed = 0.0;
}

void	game_init(t_game *game)
{
	malloc_z_buffer(game);
	malloc_buffer(game);
	load_texture(game);
	linux_resolution_max_min_check(game);
	game->img.img_ptr = mlx_new_image(game->mlx, game->info.win_width,
			game->info.win_height);
	game->img.data = (int *)mlx_get_data_addr(game->img.img_ptr,
			&game->img.bpp, &game->img.size_l, &game->img.endian);
}
