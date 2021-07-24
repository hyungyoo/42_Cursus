#include "../cub3d.h"

void	find_info(t_game *game, char **av)
{
	char	*line;

	game->fd = open(av[1], O_RDONLY);
	if (game->fd < 0)
		error_msg("ERROR: file not exist");
	while ((get_next_line(game->fd, &line)) > 0)
	{
		if ((line[0] == '\0' || empty_line_check(line) == 1)
			&& game->info.mark != MAP)
		{
			free(line);
			continue ;
		}
		game->info.mark = find_and_store_info(game, line);
		if (game->info.mark == -1)
			error_msg("ERROR: Parsing error");
		if (game->info.mark == MAP)
			break ;
		free(line);
	}
	game->info.line = line;
}

int	find_and_store_info(t_game *game, char *line)
{
	if (line[0] == 'R' && line[1] == ' ')
		return (store_resolution(game, line));
	else if (line[0] == 'N' && line[1] == 'O')
		return (store_texture(TEX_NORTH, game, line));
	else if (line[0] == 'S' && line[1] == 'O')
		return (store_texture(TEX_SOUTH, game, line));
	else if (line[0] == 'W' && line[1] == 'E')
		return (store_texture(TEX_WEST, game, line));
	else if (line[0] == 'E' && line[1] == 'A')
		return (store_texture(TEX_EAST, game, line));
	else if (line[0] == 'F' && line[1] == ' ')
		return (store_color(FLOOR, game, line));
	else if (line[0] == 'C' && line[1] == ' ')
		return (store_color(CEILING, game, line));
	else if (map_component_check(line))
		return (MAP);
	return (-1);
}

int	store_texture(int texture, t_game *game, char *line)
{
	int	i;
	int	fd_tex;

	i = 0;
	fd_tex = 0;
	if (game->info.tex_path[texture] != NULL)
		error_msg("ERROR: Texture path doubled");
	while (ft_uppercase(line[i]))
		i++;
	while (ft_space(line[i]))
		i++;
	if (line[i] == '\0')
		error_msg("ERROR: Texture path not exist");
	game->info.tex_path[texture] = ft_strdup(&line[i]);
	if (ft_strstr_cub(game->info.tex_path[texture], ".xpm") != 1)
		error_msg("ERROR: .xpm not corrected");
	fd_tex = open(game->info.tex_path[texture], O_RDONLY);
	if (fd_tex < 0)
		error_msg("ERROR: texture .xpm file doesn't exist");
	close(fd_tex);
	return (texture);
}
