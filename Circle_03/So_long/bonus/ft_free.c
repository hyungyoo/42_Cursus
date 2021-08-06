#include "../so_long_bonus.h"

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
	if (all->enemy0.img)
	{
		mlx_destroy_image(all->mlx.mlx, all->enemy0.img);
		mlx_destroy_image(all->mlx.mlx, all->enemy1.img);
		mlx_destroy_image(all->mlx.mlx, all->enemy2.img);
		mlx_destroy_image(all->mlx.mlx, all->enemy3.img);
	}
}
