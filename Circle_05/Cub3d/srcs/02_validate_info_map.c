/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_validate_info_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:09:02 by seyun             #+#    #+#             */
/*   Updated: 2021/12/03 16:19:47 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate_info(t_game *game)
{
	if (!game->tex.path[NORTH] || !game->tex.path[SOUTH] || \
			!game->tex.path[WEST] || !game->tex.path[EAST] \
			||game->tex.floor == -1 || game->tex.ceiling == -1)
		ft_strexit("ERROR: Texture Info Missing!");
}

void	validate_map(t_game *game)
{
	if (!game->map_width || !game->map_height)
		ft_strexit("ERROR: Invalid Map Parsing");
	if (game->player.dir == '\0')
		ft_strexit("ERROR: No Player Position Givien!");
	validate_map_horizontal(game->map, game->map_width, game->map_height);
	validate_map_vertical(game->map, game->map_width, game->map_height); //LEAKS
}

void	validate_map_horizontal(char **map, int width, int height)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		if (map[y][0] != ' ' && map[y][0] != WALL)
			ft_strexit("ERROR: Map Not Surronded By Walls! (Left Side)");
		x = 1;
		while (x < width)
		{
			while (x < width && map[y][x] == ' ')
				x++;
			if (x == width)
				break ;
			if (map[y][x - 1] == ' ' && map[y][x] != WALL)
				ft_strexit("ERROR: Map Not Surronded By Walls! (Left Side)");
			while (x < width && map[y][x] != ' ')
				x++;
			if (map[y][x - 1] != WALL)
				ft_strexit("ERROR: Map Not Surronded By Walls!(Right Side)");
		}
		y++;
	}
}

void	validate_map_vertical(char **map, int width, int height)
{
	int	x;
	int	y;

	x = 0;
	while (x < width)
	{
		if (map[0][x] != ' ' && map [0][x] != WALL)
			ft_strexit("ERROR Map Not Surronded by Walls! (Upper Side)");
		y = 1;
		while (y < height)
		{
			while (y < height && map[y][x] == ' ')
				y++;
			if (y == height)
				break ;
			if (map[y - 1][x] == ' ' && map[y][x] != WALL)
				ft_strexit("ERROR: Map Not Surronded By Walls! (Upper Side)");
			while (y < height && map[y][x] != ' ')
				y++;
			if (map[y - 1][x] != WALL)
				ft_strexit("ERROR: Map Not Surronded By Walls!(Bottom Side)");
		}
		x++;
	}
}
