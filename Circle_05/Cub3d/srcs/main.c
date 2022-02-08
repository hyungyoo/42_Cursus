#include "cub3d.h"

void	set_player(t_info *all, int i, int j)
{
	if (all->player.dir)
		ft_strexit("Error: player only can be one! 😋");
	all->player.dir = all->map[i][j];
	all->player.dir_x = -1.0;
	all->player.dir_y = 0.0;
	all->player.plane_x = 0.0;
	all->player.plane_y = 0.66;
	all->player.move_speed = 0.07;
	all->player.rot_speed = 0.08;
	all->player.x = 0.5f + j;
	all->player.y = 0.5f + i;
}

void	init_info(t_info *all)
{
	ft_memset(all->env.path, 0, 6);
	all->env.floor = -1;
	all->env.ceiling = -1;
	all->env.width = 0;
	all->env.height = 0;
	all->line = NULL;
	all->player.dir = '\0';
	all->render_buf = NULL;
	all->window_width = 1680;
	all->window_height = 1050;
}

void	set_player_direction(t_info *all)
{
	int	degree;

	degree = 0;
	if (all->player.dir == 'N')
		degree = 90;
	else if (all->player.dir == 'S')
		degree = 270;
	else if (all->player.dir == 'E')
		degree = 0;
	else if (all->player.dir == 'W')
		degree = 180;
	rotate_player(&all->player, degree * PI / 180);
}

int	main(int argc, char **argv)
{
	t_info	all;

	if (argc != 2)
		ft_strexit("Error: Argument Error!👎👎👎👎👎");
	init_info(&all);
	fd_open_error(argv[1], &all);
	read_line_map(&all);
	check_map(&all);
	allocate_map(&all);
	validate_map(&all);
	arrange_game(&all);
	execute_game(&all);
	return (0);
}
