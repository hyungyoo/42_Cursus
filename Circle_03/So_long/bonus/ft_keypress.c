/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:14:07 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/07 16:37:03 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_swap(t_map *map, int	ex_x, int ex_y)
{
	if (map->flag_exit == 0)
		map->map_array[map->p_x][map->p_y] = '0';
	else
		map->map_array[map->p_x][map->p_y] = 'E';
	map->map_array[ex_x][ex_y] = 'P';
	map->p_x = ex_x;
	map->p_y = ex_y;
	map->flag_exit = 0;
}

void	ft_exit_player(t_info *all, int ex_x, int ex_y)
{
	if (all->map.num_collectible == 0)
	{
		ft_free(all);
		exit(0);
	}
	ft_swap(&(all->map), ex_x, ex_y);
	all->map.flag_exit = 1;
}

void	ft_collecte(t_info *all, int ex_x, int ex_y)
{
	ft_swap(&(all->map), ex_x, ex_y);
	all->map.num_collectible -= 1;
}

void	ft_move(t_info *all, int i, int j)
{
	int	ex_x;
	int	ex_y;

	ex_x = all->map.p_x + i;
	ex_y = all->map.p_y + j;
	if (all->map.map_array[ex_x][ex_y] == '0')
		ft_swap(&(all->map), ex_x, ex_y);
	else if (all->map.map_array[ex_x][ex_y] == '1')
		all->count_mouvement--;
	else if (all->map.map_array[ex_x][ex_y] == 'E')
		ft_exit_player(all, ex_x, ex_y);
	else if (all->map.map_array[ex_x][ex_y] == 'C')
		ft_collecte(all, ex_x, ex_y);
	else if (all->map.map_array[ex_x][ex_y] == 'N')
		ft_exit_enemy(all, ex_x, ex_y);
}

void	ft_player_move(t_info *all, char c)
{
	if (c == 'U' || c == 'D'
		|| c == 'L' || c == 'R')
	{
		all->count_mouvement++;
		if (c == 'U')
			ft_move(all, -1, 0);
		else if (c == 'D')
			ft_move(all, 1, 0);
		else if (c == 'L')
			ft_move(all, 0, -1);
		else if (c == 'R')
			ft_move(all, 0, 1);
	}
}
