#include "cub3d.h"

void	read_line_map(t_info *all)
{
	char	*line;
	char	**map_split;
	int		flag;

	line = NULL;
	while (get_next_line(all->fd, &line) > 0)
	{
		if (line[0] == '\0')
		{
			free(line);
			line = NULL;
			continue ;
		}
		map_split = ft_split(line, ' ');
		if (!map_split)
			ft_strexit("Error: Split error!😖");
		flag = direction_info_map(all, map_split);
		ft_free_double(map_split);
		if (flag == MAP_START)
			break ;
		free(line);
		line = NULL;
	}
	all->line = line;
}

/* man_split[0] -> NO
 * man_split[1] -> ./texture/tile2.xpm
 */
int	direction_info_map(t_info *all, char **map_split)
{
	if (!ft_strcmp(map_split[0], "NO"))
		xpm_parsing(all, map_split[1], NORTH);
	else if (!ft_strcmp(map_split[0], "SO"))
		xpm_parsing(all, map_split[1], SOUTH);
	else if (!ft_strcmp(map_split[0], "WE"))
		xpm_parsing(all, map_split[1], WEST);
	else if (!ft_strcmp(map_split[0], "EA"))
		xpm_parsing(all, map_split[1], EAST);
	else if (!ft_strcmp(map_split[0], "F"))
		floor_ceiling_color(all, map_split[1], F);
	else if (!ft_strcmp(map_split[0], "C"))
		floor_ceiling_color(all, map_split[1], C);
	else
		return (MAP_START);
	return (0);
}

/* map_split[0] -> C
 * map_split[1] -> 255, 255,0 ,0
 */
void	floor_ceiling_color(t_info *all, char *rgb_with_comma, int flag)
{
	char	**rgb;
	int		hex;
	int		rgb_num;
	int		i;

	rgb = ft_split(rgb_with_comma, ',');
	if (!rgb)
		ft_strexit("Error: rgb split error!🚦");
	i = 0;
	hex = 0;
	while (i < 3)
	{
		if (!rgb[i] || !ft_only_digit(rgb[i]))
			ft_strexit("Error: rgb color info is incomplete!🥶");
		rgb_num = ft_atoi(rgb[i]);
		if (rgb_num > 255 || rgb_num < 0)
			ft_strexit("Error: rgb color range is invalid! 😈 ");
		hex = hex * 256 + rgb_num;
		i++;
	}
	if (flag == F)
		all->env.floor = hex;
	else if (flag == C)
		all->env.ceiling = hex;
	ft_free_double(rgb);
}
