#include "../cub3d.h"

void	read_map(t_game *game, char *line)
{
	game->map.tmp = ft_strjoin(line, "\n");
	while ((get_next_line(game->fd, &line) > 0))
	{
		if (line[0] == '\0' || empty_line_check(line) == 1)
		{
			free(line);
			error_msg("ERROR: Empty line in the map");
		}
		game->map.tmp = tmp_map_update(game->map.tmp, line);
		free(line);
	}
	free(line);
	close(game->fd);
	allocate_map(game);
	complet_map(game);
}

void	find_map_width_and_height(t_game *game)
{
	int	i;
	int	x;
	int	len;

	i = 0;
	x = 0;
	len = 0;
	game->map.buff = ft_split(game->map.tmp, '\n');
	if (!(game->map.buff))
		error_msg("ERROR: Map split failed");
	free(game->map.tmp);
	while (game->map.buff[i])
	{
		len = ft_strlen(game->map.buff[i]);
		if (x < len)
			x = len;
		i++;
	}
	game->map.width_count = x;
	game->map.height_count = i;
}

void	allocate_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	find_map_width_and_height(game);
	game->map.map = malloc(sizeof(char *) * (game->map.height_count + 1));
	if (!(game->map.map))
		error_msg("ERROR: Malloc failed");
	game->map.map[game->map.height_count] = NULL;
	while (game->map.buff[i])
	{
		game->map.map[i] = malloc(sizeof(char) * (game->map.width_count + 1));
		if (!(game->map.map[i]))
			error_msg("ERROR: Malloc failed");
		j = 0;
		while (j < game->map.width_count)
		{
			game->map.map[i][j] = ' ';
			j++;
		}
		game->map.map[i][game->map.width_count] = '\0';
		i++;
	}
}

void	complet_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (j < ft_strlen(game->map.buff[i]))
		{
			if (!map_component_check(&game->map.buff[i][j])
											&& game->map.buff[i][j] != '\0')
				error_msg("ERROR: Invalide component in the map");
			game->map.map[i][j] = game->map.buff[i][j];
			if (player_check(game->map.map[i][j], "NSEW") == 1)
			{
				create_player(game, i, j);
				game->map.map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	free_tab2(game->map.buff);
}

char	*tmp_map_update(char *first_map_line, char *line)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_strjoin(line, "\n");
	tmp2 = ft_strjoin(first_map_line, tmp1);
	if (*first_map_line && first_map_line)
	{
		free(first_map_line);
		first_map_line = NULL;
	}
	free(tmp1);
	return (tmp2);
}
