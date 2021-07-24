#include "../cub3d.h"

int	store_color(int info, t_game *game, char *line)
{
	int		i;
	int		color;
	char	**rgb;

	i = 0;
	color = 0;
	check_color_line(game, line, &info, &i);
	rgb = ft_split(&line[i], ',');
	if (!rgb)
		error_msg("ERROR: RGB Split error");
	i = 0;
	find_color(line, &i, rgb, &color);
	if (info == FLOOR)
		game->info.floor_color = color;
	else if (info == CEILING)
		game->info.ceiling_color = color;
	free_tab2(rgb);
	return (info);
}

void	check_color_line(t_game *game, char *line, int *info, int *i)
{
	if ((game->info.mark == *info && game->info.floor_color != -1)
		|| (game->info.mark == *info && game->info.ceiling_color != -1))
		error_msg("ERROR: Color info doubled");
	while (ft_uppercase(line[*i]))
		(*i)++;
	while (ft_space(line[*i]))
		(*i)++;
}

void	find_color(char *line, int *i, char **rgb, int *color)
{
	int	tmp;
	int	j;

	j = *i;
	while (*i < 3)
	{
		if (!rgb[*i] || !ft_only_digit(rgb[*i]))
			error_msg("ERROR: RGB info not corrected");
		tmp = ft_atoi(rgb[*i]);
		if (tmp > 255 || tmp < 0)
			error_msg("ERROR: RGB range invalid");
		*color = *color * 256 + tmp;
		(*i)++;
	}
	while (line[j] != '\0')
	{
		if (line[j] == ',' && line[j + 1] == '\0')
			error_msg("ERROR: Unexpected comma exist");
		j++;
	}
	if (rgb[3])
		error_msg("ERROR: Too many color for RGB");
}
