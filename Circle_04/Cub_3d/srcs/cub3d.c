#include "../cub3d.h"

int	main_loop(t_game *game)
{
	ray_processing(game);
	render_screen(game);
	return (0);
}

void	game_set_go(t_game *game)
{
	game->win = mlx_new_window(game->mlx, game->info.win_width,
			game->info.win_height, TITLE);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 1L << 17, &ft_exit_key, game);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 1L << 0, &ft_keypress, game);
	mlx_loop_hook(game->mlx, &main_loop, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	t_game	game;

	all_init(&game);
	file_validation_check(ac, av);
	find_info(&game, av);
	info_validation_check(&game);
	read_map(&game, game.info.line);
	map_validation_check(&game);
	game_init(&game);
	game_set_go(&game);
	return (EXIT_SUCCESS);
}
