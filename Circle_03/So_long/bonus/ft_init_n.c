/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 20:45:01 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/10 16:55:08 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_wall_left(t_map *map, int i, int j)
{
	int	nx;
	int	ny;

	nx = map->n_x + i;
	ny = map->n_y + j;
	if (map->map_array[nx][ny] == '0')
	{
		map->map_array[nx][ny] = 'N';
		map->map_array[map->n_x][map->n_y] = '0';
		map->n_y = ny;
		map->n_x = nx;
	}
	else 
		if (map->map_array[map->n_x - 1][map->n_y] == '0') 
			ft_wall_left(map, -1, 0);
}

int	ft_enemy_left(t_map *map)
{
	if (!(map->n_y > 1 && map->n_x > 1))
		return (0);
	else
	{
		ft_wall_left(map, 0, -1);
		return (1);
	}

}
void	ft_wall_right(t_map *map, int i, int j)
{
	int	nx;
	int	ny;

	nx = map->n_x + i;
	ny = map->n_y + j;
	if (map->map_array[nx][ny] == '0')
	{
		map->map_array[nx][ny] = 'N';
		map->map_array[map->n_x][map->n_y] = '0';
		map->n_y = ny;
		map->n_x = nx;
	}
	else
		if (map->map_array[map->n_x + 1][map->n_y] == '0') 
			ft_wall_right(map, 1, 0);
}

int	ft_enemy_right(t_map *map)
{
	if (map->n_y != map->num_cols - 1 && map->n_x != map->num_rows - 1)
	{
		ft_wall_right(map, 0, 1);
		return (1);
	}
	return (0);
}

void	ft_enemy(t_map *map)
{
	int	flag;

	flag = ft_enemy_right(map);
	if (flag == 0)
		while (map->n_y != 1 && map->n_x != 1)
			ft_enemy_left(map);
}

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
