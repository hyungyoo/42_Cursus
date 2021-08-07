/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 21:02:25 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/07 21:45:33 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"	

void	ft_setup_bonus(t_info *all)
{
	int		i;
	int		j;

	i = -1;
	while (++i < all->map.num_cols)
	{
		j = -1;
		while (++j < all->map.num_rows)
		{
			if (all->map.map_array[j][i] == 'C')
			{
				mlx_put_image_to_window(all->mlx.mlx, all->mlx.win_mlx,
					all->enemy0.img, i * TILE_SIZE, j * TILE_SIZE);
				mlx_put_image_to_window(all->mlx.mlx, all->mlx.win_mlx,
					all->enemy1.img, i * TILE_SIZE, j * TILE_SIZE);
				mlx_put_image_to_window(all->mlx.mlx, all->mlx.win_mlx,
					all->enemy2.img, i * TILE_SIZE, j * TILE_SIZE);
				mlx_put_image_to_window(all->mlx.mlx, all->mlx.win_mlx,
					all->enemy3.img, i * TILE_SIZE, j * TILE_SIZE);
			}
		}
	}
}
