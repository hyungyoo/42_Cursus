/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_execute_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 22:52:15 by seyun             #+#    #+#             */
/*   Updated: 2021/12/02 23:06:47 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	execute_ray(t_game *game)
{
	ray_background(game);
	render(game);
	return (0);
}

void	ray_background(t_game *game)
{
	int	x;

	x = 0;
	set_floor_ceiling_color(game);
	while (x < game->width)
	{
		init_ray(game, &game->player, &game->ray, x);
		calculate_step_direction(&game->player, &game->ray);
		perform_dda(game, &game->ray);
		calculate_wall_distance(&game->player, &game->ray);
		calculate_wall_height(game, &game->ray);
		set_wall_texture(&game->player, &game->ray);
		set_wall_color(game, &game->ray, x);
		x++;
	}
}

void	render(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			game->img.data[game->width * y + x] = game->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.ptr, 0, 0);
}
