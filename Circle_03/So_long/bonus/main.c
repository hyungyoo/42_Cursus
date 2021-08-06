/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:31:57 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/06 20:04:26 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"	

void	ft_put_string(t_info *all)
{
	char	*num;

	num = ft_itoa(all->count_mouvement);
	mlx_string_put(all->mlx.mlx, all->mlx.win_mlx,
		10, 10, 0xFFFFFF, "count : ");
	mlx_string_put(all->mlx.mlx, all->mlx.win_mlx, 70,
		10, 0xFFFFFF, num);
	free(num);
}

void	ft_setup_1(t_info *all)
{
	int		i;
	int		j;

	i = -1;
	while (++i < all->map.num_cols)
	{
		j = -1;
		while (++j < all->map.num_rows)
		{
			if (all->map.map_array[j][i] == '1')
			{
				mlx_put_image_to_window(all->mlx.mlx, all->mlx.win_mlx,
					all->wall.img, i * TILE_SIZE, j * TILE_SIZE);
				ft_put_string(all);
			}
			else if (all->map.map_array[j][i] == 'P' && all->map.flag_exit)
				mlx_put_image_to_window(all->mlx.mlx, all->mlx.win_mlx,
					all->player_exit.img, i * TILE_SIZE, j * TILE_SIZE);
			else if (all->map.map_array[j][i] == 'P')
				mlx_put_image_to_window(all->mlx.mlx, all->mlx.win_mlx,
					all->player.img, i * TILE_SIZE, j * TILE_SIZE);
		}
	}
}

void	ft_setup_2(t_info *all)
{
	int	i;
	int	j;

	i = 0;
	while (i < all->map.num_cols)
	{
		j = 0;
		while (j < all->map.num_rows)
		{
			if (all->map.map_array[j][i] == '0')
				mlx_put_image_to_window(all->mlx.mlx, all->mlx.win_mlx,
					all->floor.img, i * TILE_SIZE, j * TILE_SIZE);
			else if (all->map.map_array[j][i] == 'E')
				mlx_put_image_to_window(all->mlx.mlx, all->mlx.win_mlx,
					all->exit.img, i * TILE_SIZE, j * TILE_SIZE);
			else if (all->map.map_array[j][i] == 'C')
				mlx_put_image_to_window(all->mlx.mlx, all->mlx.win_mlx,
					all->collectible.img, i * TILE_SIZE, j * TILE_SIZE);
			j++;
		}
		i++;
	}
}

int	ft_loop(t_info *all)
{
	ft_setup_1(all);
	ft_setup_2(all);
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
	all.count_mouvement = 0;
	all.mlx.mlx = mlx_init();
	all.mlx.win_mlx = mlx_new_window(all.mlx.mlx, all.mlx.window_width,
			all.mlx.window_height, "So_Long");
	ft_init_xpm(&all);
	mlx_hook(all.mlx.win_mlx, 2, 1L << 0, &keypress_event, &all);
	mlx_hook(all.mlx.win_mlx, 17, 0, &keypress, 0);
	mlx_loop_hook(all.mlx.mlx, &ft_loop, &all);
	mlx_loop(all.mlx.mlx);
	ft_free(&all);
	return (0);
}
