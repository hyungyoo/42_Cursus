/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_read_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 22:59:33 by seyun             #+#    #+#             */
/*   Updated: 2021/12/03 00:01:53 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_info(t_game *game)
{
	char	*line;
	char	**info;
	int		flag;

	line = NULL;
	while (get_next_line(game->fd, &line) > 0)
	{
		if (line[0] == EMPTY_LINE)
			continue ;
		info = ft_split(line, ' ');
		if (!info)
			ft_strexit("ERROR: Split Fail!");
		flag = decide_info_map(game, info);
		ft_free_double(info);
		if (flag == MAP_START)
			break ;
		free (line);
	}
	game->line = line;
}

int	decide_info_map(t_game *game, char **info)
{
	if (ft_strcmp(info[0], "NO") == 0)
		game_texture(game, info[1], NORTH);
	else if (ft_strcmp(info[0], "SO") == 0)
		game_texture(game, info[1], SOUTH);
	else if (ft_strcmp(info[0], "WE") == 0)
		game_texture(game, info[1], WEST);
	else if (ft_strcmp(info[0], "EA") == 0)
		game_texture(game, info[1], EAST);
	else if (ft_strcmp(info[0], "F") == 0)
		game_color(game, info[1], FLOOR);
	else if (ft_strcmp(info[0], "C") == 0)
		game_color(game, info[1], CEILING);
	else
		return (MAP_START);
	return (0);
}

void	game_texture(t_game *game, char *xpm_path, int flag)
{
	int	fd;

	if (!xpm_path || !ft_isformat(xpm_path, ".xpm"))
		ft_strexit("ERROR: Path To XPM Needed!");
	fd = open(xpm_path, O_RDONLY);
	if (fd == -1)
		ft_strexit("ERROR: No Such XPM Available!");
	close(fd);
	game->tex.path[flag] = ft_strdup(xpm_path);
}

void	game_color(t_game *game, char *rgb_with_comma, int flag)
{
	char	**rgb;
	int		hex;
	int		tmp;
	int		i;

	rgb = ft_split(rgb_with_comma, ',');
	if (!rgb)
		ft_strexit("ERROR: Split Fail!");
	i = 0;
	hex = 0;
	while (i < 3)
	{
		if (!rgb[i] || !ft_only_digit(rgb[i]))
			ft_strexit("ERROR: RGB Info Incompete!");
		tmp = ft_atoi(rgb[i]);
		if (tmp > 255 || tmp < 0)
			ft_strexit("ERROR: RGB Range Invalide!");
		hex = hex * 256 + tmp;
		i++;
	}
	if (flag == FLOOR)
		game->tex.floor = hex;
	else if (flag == CEILING)
		game->tex.ceiling = hex;
		ft_free_double(rgb);
}
