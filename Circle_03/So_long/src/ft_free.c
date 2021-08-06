#include "../so_long.h"

void	ft_free(t_info *all)
{
	int	i;

	i = 0;
	while (all->map.map_array[i])
		free(all->map.map_array[i++]);
	free(all->map.map_array);
	close(all->map.fd);
	close(all->map.fd2);
	mlx_destroy_image(all->mlx.mlx, all->wall.img);
	mlx_destroy_image(all->mlx.mlx, all->floor.img);
	mlx_destroy_image(all->mlx.mlx, all->player.img);
	mlx_destroy_image(all->mlx.mlx, all->collectible.img);
	mlx_destroy_image(all->mlx.mlx, all->player_exit.img);
	mlx_destroy_window(all->mlx.mlx, all->mlx.win_mlx);
}
