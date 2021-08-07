/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:22:40 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/07 19:28:25 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_init(t_info *all)
{
	all->mlx.mlx = 0;
	all->mlx.win_mlx = 0;
	all->wall.img = 0;
	all->floor.img = 0;
	all->player.img = 0;
	all->collectible.img = 0;
	all->exit.img = 0;
	all->player_exit.img = 0;
	all->map.map_array = NULL;
}



