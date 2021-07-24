#include "../cub3d.h"

int	map_component_check(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_strchr("01NSEW ", line[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

int	empty_line_check(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	malloc_buffer(t_game *game)
{
	int	i;

	game->buf = ft_calloc(game->info.win_height + 1, sizeof(int **));
	if (!(game->buf))
		error_msg("ERROR: Buffer malloc failed");
	i = 0;
	while (i < game->info.win_height)
	{
		game->buf[i] = ft_calloc(game->info.win_width + 1, sizeof(int *));
		if (!(game->buf[i]))
			error_msg("ERROR: Buffer malloc failed");
		i++;
	}
}

void	malloc_z_buffer(t_game *game)
{
	game->z_buffer = (double *)ft_calloc(game->info.win_width, sizeof(double));
	if (!(game->z_buffer))
		error_msg("ERROR: z_buffer malloc failed");
}
