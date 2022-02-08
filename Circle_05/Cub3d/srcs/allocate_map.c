#include "cub3d.h"

void	allocate_map(t_info	*all)
{
	int	i;

	i = 0;
	all->env.height = get_size_map(all);
	all->map = (char **)malloc(sizeof(char *) * (all->env.height + 1));
	if (!(all->map))
		ft_strexit("Error: malloc error!");
	all->map[all->env.height] = NULL;
	(all->map)[i++] = strdup_line(all->line, all->env.width);
	free(all->line);
	all->line = NULL;
	while (get_next_line(all->fd, &all->line) > 0)
	{
		if (all->line[0] == '\0')
			ft_strexit("Error: map error!");
		(all->map)[i++] = strdup_line(all->line, all->env.width);
		free(all->line);
		all->line = NULL;
	}
	close(all->fd);
}

char	*strdup_line(char *str, int size)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char *) malloc(sizeof(char) * size + 1);
	if (!ret)
		ft_strexit("Error: malloc error!");
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	while (i < size)
		ret[i++] = ' ';
	ret[i] = '\0';
	return (ret);
}

static void	get_size_map_gnl(int *size, t_info *all, int *flag)
{
	char	*line;

	line = NULL;
	all->env.width = 0;
	while (get_next_line(all->fd_map, &line) > 0)
	{
		if (*flag && line[0] == '\0')
			break ;
		if (line[0] == '\0')
		{
			free(line);
			line = NULL;
			continue ;
		}
		*flag = get_flag(line);
		if (*flag)
		{
			(*size)++;
			if ((int)ft_strlen(line) > all->env.width)
				all->env.width = (int)ft_strlen(line);
		}
		free(line);
	}
	free(line);
}

/* setting width, height*/
int	get_size_map(t_info *all)
{
	int		size;
	int		flag;

	flag = 0;
	size = 0;
	get_size_map_gnl(&size, all, &flag);
	close(all->fd_map);
	return (size);
}

bool	get_flag(char *line)
{
	bool	flag;
	char	**map_split;

	flag = false;
	map_split = ft_split(line, ' ');
	if (!(!ft_strcmp(map_split[0], "NO") || !ft_strcmp(map_split[0], "SO")
			|| !ft_strcmp(map_split[0], "WE") || !ft_strcmp(map_split[0], "EA")
			|| !ft_strcmp(map_split[0], "F") || !ft_strcmp(map_split[0], "C")))
		flag = true;
	ft_free_double(map_split);
	return (flag);
}
