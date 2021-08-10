/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:22:40 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/10 17:05:51 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_init_n(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_array[i])
	{
		j = 0;
		while (map->map_array[i][j])
		{
			if (map->map_array[i][j] == '0')
			{
				map->n_x = i;
				map->n_y = j;
				map->map_array[i][j] = 'N';
				return ;
			}
			j++;
		}
		i++;
	}
	ft_print_error2("Error: pas de place pour enemy", map);
}

void	ft_init(t_info *all)
{
	all->mlx.mlx = 0;
	all->mlx.win_mlx = 0;
	all->wall.img = 0;
	all->floor.img = 0;
	all->player.img = 0;
	all->collectible.img = 0;
	all->exit.img = 0;
	all->enemy0.img = 0;
	all->enemy1.img = 0;
	all->enemy2.img = 0;
	all->enemy3.img = 0;
	all->player_exit.img = 0;
	all->map.map_array = NULL;
}
