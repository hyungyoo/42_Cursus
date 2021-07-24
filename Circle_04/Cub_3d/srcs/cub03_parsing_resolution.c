#include "../cub3d.h"

int	store_resolution(t_game *game, char *line)
{
	int	i;

	i = 0;
	if (game->info.win_width || game->info.win_height)
		error_msg("ERROR: Resolution info doubled");
	find_resolution(game, line, &i);
	if (!game->info.win_width || !game->info.win_height)
		error_msg("ERROR: One of resolutions is invalid");
	while (ft_space(line[i]))
		i++;
	if (line[i] != '\0')
		error_msg("ERROR: Resolution info not corrected");
	return (RESOLUTION);
}

void	find_resolution(t_game *game, char *line, int *i)
{
	while (ft_uppercase(line[*i]))
		(*i)++;
	while (ft_space(line[*i]))
		(*i)++;
	while (ft_digit(line[*i]))
		game->info.win_width = game->info.win_width * 10 + line[(*i)++] - 48;
	while (ft_space(line[*i]))
		(*i)++;
	if (ft_digit(line[*i]))
	{
		while (ft_digit(line[*i]))
			game->info.win_height = game->info.win_height * 10
				+ line[(*i)++] - 48;
	}
	else
		error_msg("ERROR: Resolution info not corrected");
}
