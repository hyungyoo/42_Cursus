/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:31:57 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/05 15:23:01 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"	

void	ft_setup(t_info *all)
{
	int	i;
	int	j;

	i = 0;
	while (i < all->map.num_rows)
	{
		j = 0;
		while (j < all->map.num_cols)
		{
			if (all->map.map_array[i][j] == '1')
				mlx_put_image_to_window(all->mlx.mlx, all->mlx.win_mlx, all->wall.img, i * TILE_SIZE, j * TILE_SIZE);
			else if (all->map.map_array[i][j] == '0')
				mlx_put_image_to_window(all->mlx.mlx, all->mlx.win_mlx, all->floor.img, i * TILE_SIZE, j * TILE_SIZE);
			else if (all->map.map_array[i][j] == 'P')
				mlx_put_image_to_window(all->mlx.mlx, all->mlx.win_mlx, all->player.img, i * TILE_SIZE, j * TILE_SIZE);
			else if (all->map.map_array[i][j] == 'E')
				mlx_put_image_to_window(all->mlx.mlx, all->mlx.win_mlx, all->exit.img, i * TILE_SIZE, j * TILE_SIZE);
			else if (all->map.map_array[i][j] == 'C')
				mlx_put_image_to_window(all->mlx.mlx, all->mlx.win_mlx, all->collectible.img, i * TILE_SIZE, j * TILE_SIZE);
			j++;
		}
		i++;
	}

}

int	ft_loop(t_info *all)
{
	ft_setup(all);
	return (0);
}

/*
* line * ~ *
* ft_print_error.c
*/
int	main(int argc, char **argv)
{
	t_info	all;

	if (!(argc == 2 && ft_file_name(argv[1], ".ber")))
		ft_print_error("to use :./so_long maps/*.ber");
	ft_map(argv[1], &all);

	all.mlx.mlx = mlx_init();
	all.mlx.win_mlx = mlx_new_window(all.mlx.mlx, all.mlx.window_height, all.mlx.window_width, "So_Long");
	ft_init_xpm(&all);
	mlx_hook(all.mlx.win_mlx, 2, 1L<<0, &keypress_event, &all);
	mlx_hook(all.mlx.win_mlx, 17, 0, &keypress, 0);
	

	mlx_loop_hook(all.mlx.mlx, &ft_loop, &all);
	mlx_loop(all.mlx.mlx);
	//ft_free(&all);
	return (0);
}
