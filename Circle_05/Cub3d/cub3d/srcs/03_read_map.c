/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:09:48 by seyun             #+#    #+#             */
/*   Updated: 2021/12/03 16:06:59 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_map(t_game *game, char *line)
{
	game->lst = ft_lstnew(ft_strdup(line));
	free(line);
	while (get_next_line(game->fd, &line) > 0)
	{
		if (line[0] == EMPTY_LINE)
			break ;
		ft_lstadd_back(&game->lst, ft_lstnew(ft_strdup(line)));
		free(line);
	}
	free(line);
	allocate_map(game, game->lst);
	store_map(game, game->lst);
	ft_lstclear(&(game->lst), free); // NULL ok
}

void	allocate_map(t_game *game, t_list *curr)
{
	int	i;
	int	j;

	game->map_height = ft_lstsize(curr);
	game->map_width = ft_longest_node_len(curr);
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		ft_strexit("ERROR: Malloc Fail!");
	game->map[game->map_height] = NULL;
	i = 0;
	while (curr)
	{
		game->map[i] = malloc(sizeof(char) * (game->map_width + 1));
		if (!game->map[i])
			ft_strexit("ERROR: Malloc Fail!");
		j = 0;
		while (j < game->map_width)
		{
			game->map[i][j] = ' ';
			j++;
		}
		game->map[i][game->map_width] = '\0';
		i++;
		curr = curr->next;
	}
}

void	store_map(t_game *game, t_list *curr)
{
	int		i;
	size_t	j;
	char	*content;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		content = (char *)curr->content;
		while (j < ft_strlen(content))
		{
			if (!ft_isset(content[j], "NSWE01 \n") && content[j] != '\0')
				ft_strexit("ERROR: Invalid Map Element Contained!");
			game->map[i][j] = content[j];
			if (ft_isset(content[j], "NSWE"))
				create_player(game, i, j);
			j++;
		}
		curr = curr->next;
		i++;
	}
}

void	create_player(t_game *game, int i, int j)
{
	if (game->player.dir)
		ft_strexit("ERROR: Multiple Player Given!");
	game->player.dir = game->map[i][j];
	game->player.x = 2;
	game->player.y = 5;
	game->player.dir_x = -1.0;
	game->player.dir_y = 0.0;
	game->player.plane_x = 0.0;
	game->player.plane_y = 0.66;
	game->player.move_speed = 0.07;
	game->player.rot_speed = 0.08;
	game->player.x = 0.5f + j;
	game->player.y = 0.5f + i;
}
